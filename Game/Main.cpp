#include "Gaem.h"

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

	unique_ptr<Gaem> game = make_unique<Gaem>();

	// Assets

	bool quit = false;
	while (!quit)
	{
		// Update
		en::Update(); // Update Engine

		game->Update();

		// Global Checks
		if (en::__inputsys.keyPressed(en::key_escape)) quit = true;

		// Draw
		en::__renderer.beginFrame();

		// Draw Here
		game->Draw(en::__renderer);

		en::__renderer.endFrame();
	}

	// System Shutdown
	game->Shutdown();
	game.reset();
	en::Shutdown();
}