#include "PhysicsSystem.h"

namespace en
{
	void PhysicsSystem::Init()
	{
		b2Vec2 gravity{ 0.0f, 9.82f };
		world = std::make_unique<b2World>(gravity);
	}

	void PhysicsSystem::Shutdown()
	{
		// TODO
	}

	void PhysicsSystem::Update()
	{
		// TODO
	}
}
