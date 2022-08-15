#include "Engine.h"

namespace en
{
	void Init()
	{
		en::__renderer.Init();
		en::__inputsys.Init();
		en::__audiosys.Init();
		en::__registry.Init();
	}

	void Update()
	{
		en::__audiosys.Update();
		en::__inputsys.Update();
		en::__time.Tick();
	}

	void Shutdown()
	{
		en::__audiosys.Shutdown();
		en::__renderer.Shutdown();
		en::__inputsys.Shutdown();
		en::__registry.Shutdown();
	}

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
	}

	InputSystem __inputsys;
	Time __time;
	Renderer __renderer;
	AudioSys __audiosys;
	ResourceManager __registry;
}