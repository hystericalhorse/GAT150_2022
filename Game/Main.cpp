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

	// Image
	shared_ptr<en::Texture> texture = make_unique<en::Texture>();
	texture->Create(en::__renderer, "image.png");

	// Variables
	float angle = 0.0f;

	bool quit = false;
	while (!quit)
	{
		// Update
		en::Update();
		angle += 30 * en::__time.ci_time;

		// Global Checks
		if (en::__inputsys.keyPressed(en::key_escape)) quit = true;

		// Draw
		en::__renderer.beginFrame();

		// Draw Here
		en::__renderer.Draw(texture, { 400, 300 }, angle, { 0.5, 0.5 });

		en::__renderer.endFrame();
	}

	// System Shutdown
	en::Shutdown();
}