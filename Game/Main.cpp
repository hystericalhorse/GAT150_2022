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
	auto texture = en::__registry.Get<en::Texture>("image/player.png", &en::__renderer);
	auto model1 = en::__registry.Get<en::Model>("model/m_starburst.txt");
	model1->setColor({ 255, 255, 255, 255 });
	int f_size = 24;
	auto font = en::__registry.Get<en::Font>("font/VCR_OSD_MONO.ttf", &f_size);

	en::__audiosys.newAudio("s_engine", "audio/static.wav");

	// Scene
	en::Scene scene;

	// Actors

	en::Transform t_player{ {400, 300}, 0.0, 10.0 };
	std::unique_ptr<en::Actor> a_player = make_unique<en::Actor>(t_player);

	std::unique_ptr<en::ModelComponent> com_model = make_unique<en::ModelComponent>();
	std::unique_ptr<en::SpriteComponent> com_sprite = make_unique<en::SpriteComponent>();
	std::unique_ptr<en::PlayerComponent> com_player = make_unique<en::PlayerComponent>();
	std::unique_ptr<en::PhysicsComponent> com_physics = make_unique<en::PhysicsComponent>();

	com_model->_model = model1;
	com_sprite->_texture = texture;

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

		cout << to_string(scene.getActor<en::Actor>()->_Transform().position.x) << endl;

		// Draw
		en::__renderer.beginFrame();

		// Draw Here
		scene.Draw(en::__renderer);

		en::__renderer.endFrame();
	}

	// System Shutdown
	en::Shutdown();
}