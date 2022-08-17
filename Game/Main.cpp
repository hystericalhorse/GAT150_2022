#include "Engine.h"

using namespace std;
int main()
{
	// Memory
	en::flag_memory_debug();

	// File Setup
	en::setPath("../Assets");

	rapidjson::Document document;
	bool success = en::json::Load("json.json", document);
	assert(success);

	std::string str;
	en::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	en::json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	en::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	en::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	en::json::Get(document, "float", f);
	std::cout << f << std::endl;

	en::Vector2 v2;
	en::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	en::Color color;
	en::json::Get(document, "color", color);
	std::cout << color << std::endl;


	// Init
	en::Init();

	// Window
	en::__renderer.newWindow("Game", 800, 600);
	en::__renderer.setClearColor(en::black);

	// Assets

	// Scene
	en::Scene scene;

	// Actors

	// Variables

	bool quit = false;
	while (!quit)
	{
		// Update
		en::Update(); // Update Engine

		scene.Update();

		// Global Checks
		if (en::__inputsys.keyPressed(en::key_escape)) quit = true;

		// Draw
		en::__renderer.beginFrame();

		// Draw Here
		scene.Draw(en::__renderer);

		en::__renderer.endFrame();
	}

	// System Shutdown
	en::Shutdown();
}