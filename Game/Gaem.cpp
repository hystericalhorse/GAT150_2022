#include "Gaem.h"

void Gaem::Init()
{
	_scene = std::make_unique<en::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "level.json" };

	for (auto object : sceneNames)
	{
		bool success = en::json::Load(object, document);
		if (!success) LOG("ERROR: Could not load scene %s", object.c_str());
		_scene->Read(document);
	}
	
	_scene->Init();

	for (int i = 0; i < en::random(10); i++)
	{
		auto actor = en::Factory::Instance().Retrieve<en::Actor>("Coin");
		actor->_Transform().position = { 500, 100 };
		actor->Init();

		_scene->addActor(std::move(actor));
	}
}

void Gaem::Shutdown()
{
	_scene->Remove();
}

void Gaem::Update()
{
	_scene->Update();
}

void Gaem::Draw(en::Renderer& renderer)
{
	_scene->Draw(renderer);
}
