#include "Gaem.h"
#include "GameComponents/EnemyComponent.h"

void Gaem::Init()
{
	REGISTER_CLASS(EnemyComponent);

	_scene = std::make_unique<en::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scene/decoration.json", "scene/prototypes.json", "scene/tilemap2.json", "scene/level.json", "scene/players.json"};

	for (auto& object : sceneNames)
	{
		bool success = en::json::Load(object, document);
		if (!success) { LOG("ERROR: Could not load scene %s", object.c_str()); continue; }
		_scene->Read(document);
	}	

	en::__eventmanager.Subscribe("EVT_EXAMPLE", std::bind(&Gaem::exampleEvent, this, std::placeholders::_1));

	_scene->Init();
	_gamestate_timer = 5.0f;
}

void Gaem::Shutdown()
{
	_scene->Shutdown();
}

void Gaem::Update()
{
	rapidjson::Document document;
	bool success;

	switch (_gamestate)
	{
	case Gaem::gameState::GameTitle:
		_gamestate_timer -= en::__time.ci_time;
		if (_gamestate_timer <= 0)
		{
			auto component = _scene->getActor("Title");
			if (component) component->toggleActive();

			_gamestate = gameState::GameStart;
		}
		break;
	case Gaem::gameState::GameStart:
		
		{
		auto actor = en::Factory::Instance().Retrieve<en::Actor>("Battery");
		actor->_Transform().position = { 1000, 500 };
		actor->Init();
		
		_scene->addActor(std::move(actor));

		actor = en::Factory::Instance().Retrieve<en::Actor>("Candy");
		actor->_Transform().position = { 200, 500 };
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