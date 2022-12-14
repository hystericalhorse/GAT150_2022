#ifndef _ENGINE_H
#define _ENGINE_H

#include "Serialization/JSON.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Core/Memory.h"
#include "Core/Logger.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Audio/AudioSys.h"

#include "Physics/PhysicsSystem.h"

#include "Framework/Background.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Factory.h"
#include "Framework/Singleton.h"
#include "Framework/EventManager.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RigidBodPhysicsComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/ModelComponent.h"
#include "Components/TextComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/TilemapComponent.h"

#include "Resource/ResourceManager.h"

#include <memory>
#include <vector>
#include <list>

namespace en
{
	void Init();
	void Update();
	void Shutdown();

	extern InputSystem __inputsys;
	extern Time __time;
	extern Renderer __renderer;
	extern AudioSys __audiosys;
	extern ResourceManager __registry;
	extern PhysicsSystem __physics;
	extern EventManager __eventmanager;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}
#endif // _ENGINE_H