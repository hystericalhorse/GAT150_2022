#include "Gaem.h"
#include "GameComponents/EnemyComponent.h"

void Gaem::Init()
{
	REGISTER_CLASS(EnemyComponent);

	_scene = std::make_unique<en::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scene/decoration.json", "scene/prototypes.json", "scene/tilemap.json", "scene/players.json", "scene/level.json" };

	for (auto& object : sceneNames)
	{
		bool success = en::json::Load(object, document);
		if (!success) { LOG("ERROR: Could not load scene %s", object.c_str()); continue; }
		_scene->Read(document);
	}	

	en::__eventmanager.Subscribe("EVT_EXAMPLE", std::bind(&Gaem::exampleEvent, this, std::placeholders::_1));

	_scene->Init();
}

void Gaem::Shutdown()
{
	_scene->Remove();
}

void Gaem::Update()
{
	switch (_gamestate)
	{
	case Gaem::gameState::GameTitle:
		
		if (en::__inputsys.getKeyState(en::key_space) == en::InputSystem::KeyState::PRESSED)
		{
			auto component = _scene->getActor("Title");
			if (component) component->toggleActive();

			_gamestate = gameState::GameStart;
		}
		break;
	case Gaem::gameState::GameStart:

		for (int i = 0; i < 2; i++)
		{
			auto actor = en::Factory::Instance().Retrieve<en::Actor>("Coin");
			actor->_Transform().position = { en::random(400), 100};
			actor->Init();

			_scene->addActor(std::move(actor));
		}

		_gamestate = gameState::Game;
		break;
	case Gaem::gameState::Game:

		break;
	case Gaem::gameState::GameOver:
		_gamestate_timer -= en::__time.ci_time;
		if (_gamestate_timer <= 0) _gamestate = gameState::GameCredits;
		break;
	case Gaem::gameState::GameCredits:

		break;
	default:
		break;
	}

	_scene->Update();
}

void Gaem::Draw(en::Renderer& renderer)
{
	_scene->Draw(renderer);
}

void Gaem::exampleEvent(const en::Event& event)
{
	std::cout << event.name << std::endl;
	std::cout << std::to_string(std::get<int>(event.data)) << std::endl;
}

void Gaem::exampleEvent2(const en::Event& event)
{
	std::cout << event.name << std::endl;
	_gamestate = gameState::GameOver;
	_gamestate_timer = 3.0f;
}