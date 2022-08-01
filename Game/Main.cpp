#include "Engine.h"

using namespace std;
int main()
{
	cout << "hello, world." << endl;

	// Memory
	en::flag_memory_debug();

	// File Stuff
	en::setPath("../Assets");

	// Init
	en::__renderer.Init();
	en::__inputsys.Init();
	en::__audiosys.Init();

	// Window
	en::__renderer.newWindow("Game", 800, 600);
	en::__renderer.setClearColor(en::Color(0, 0, 0, 255));

	bool quit = false;
	while (!quit)
	{
		// Update

		en::__audiosys.Update();
		en::__inputsys.Update();
		en::__time.tick();

		// Global Checks

		if (en::__inputsys.keyPressed(en::key_escape)) quit = true;

		// Draw
		en::__renderer.beginFrame();



		en::__renderer.endFrame();
	}

	en::__audiosys.Shutdown();
	en::__renderer.Shutdown();
	en::__inputsys.Shutdown();
}