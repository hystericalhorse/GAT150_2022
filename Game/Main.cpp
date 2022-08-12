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
	shared_ptr<en::Texture> texture = make_shared<en::Texture>();
	texture->Create(en::__renderer, "image/player.png");

	shared_ptr<en::Model> model = make_shared<en::Model>();
	model->Load("model/m_starburst.txt");

	// Audio
	en::__audiosys.newAudio("s_engine", "audio/static.wav");

	// Scene
	en::Scene scene;

	// Actors

	/*
		en::Transform t_player{ {400, 300}, 0.0, 1.0 };
		std::unique_ptr<en::Actor> a_player = make_unique<en::Actor>(t_player);
		std::unique_ptr<en::PlayerComponent> com_player = make_unique<en::PlayerComponent>();
		std::unique_ptr<en::SpriteComponent> com_sprite = make_unique<en::SpriteComponent>();
		std::unique_ptr<en::PhysicsComponent> com_physics = make_unique<en::PhysicsComponent>();
		com_sprite->_texture = texture;
		a_player->addComponent(std::move(com_sprite));
		a_player->addComponent(std::move(com_physics));
		a_player->addComponent(std::move(com_player));
		scene.Add(std::move(a_player));
	*/

	en::Transform t_player{ {400, 300}, 0.0, 2.0 };
	std::unique_ptr<en::Actor> a_player = make_unique<en::Actor>(t_player);

	std::unique_ptr<en::ModelComponent> com_model = make_unique<en::ModelComponent>();
	std::unique_ptr<en::PlayerComponent> com_player = make_unique<en::PlayerComponent>();
	std::unique_ptr<en::PhysicsComponent> com_physics = make_unique<en::PhysicsComponent>();

	com_model->_model = model;

	a_player->addComponent(std::move(com_model));
	a_player->addComponent(std::move(com_physics));
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
		//en::__renderer.Draw(texture, { 400, 300 }, angle, { 0.5, 0.5 });

		en::__renderer.endFrame();
	}

	// System Shutdown
	en::Shutdown();
}