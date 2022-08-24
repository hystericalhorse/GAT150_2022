#include "Engine.h"

using namespace std;
int main()
{
	// Memory
	en::flag_memory_debug();

	// File Setup
	en::setPath("../Assets");

	// Init
	en::Init();

	// Window
	en::__renderer.newWindow("Game", 800, 600);
	en::__renderer.setClearColor(en::black);

	// Assets

	// Scene
	en::Scene scene;

	rapidjson::Document document;
	bool success = en::json::Load("level.json", document);

	scene.Read(document);
	scene.Init();

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