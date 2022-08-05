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

	// Scene
	en::Scene scene;

	// Actors
	std::unique_ptr<en::Actor> a_player = make_unique<en::Actor>();
	std::unique_ptr<en::PlayerComponent> com_player = make_unique<en::PlayerComponent>();
	a_player->addComponent(std::move(com_player));
	scene.Add(std::move(a_player));

	// Variables
	float angle = 0.0f;

	bool quit = false;
	while (!quit)
	{
		// Update
		en::Update(); // Update Engine

		scene.Update();
		angle += 30 * en::__time.ci_time;

		// Global Checks
		if (en::__inputsys.keyPressed(en::key_escape)) quit = true;

		// Draw
		en::__renderer.beginFrame();

		// Draw Here
		scene.Draw(en::__renderer);
		en::__renderer.Draw(texture, { 400, 300 }, angle, { 0.5, 0.5 });

		en::__renderer.endFrame();
	}

	// System Shutdown
	en::Shutdown();
}