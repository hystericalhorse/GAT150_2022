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
	en::__renderer.setClearColor(en::Color(0, 0, 0, 255));

	// Image

	bool quit = false;
	while (!quit)
	{
		// Update
		en::Update();

		// Global Checks
		if (en::__inputsys.keyPressed(en::key_escape)) quit = true;

		// Draw
		en::__renderer.beginFrame();

		// Draw Here

		en::__renderer.endFrame();
	}

	// System Shutdown
	en::Shutdown();
}