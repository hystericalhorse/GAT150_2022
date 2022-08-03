#include "Engine.h"

namespace en
{
	void Init()
	{
		en::__renderer.Init();
		en::__inputsys.Init();
		en::__audiosys.Init();
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
	}

	InputSystem __inputsys;
	Time __time;
	Renderer __renderer;
	AudioSys __audiosys;
}