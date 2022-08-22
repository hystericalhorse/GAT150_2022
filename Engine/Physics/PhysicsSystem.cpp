#include "PhysicsSystem.h"

namespace en
{
	void PhysicsSystem::Init()
	{
		b2Vec2 gravity{ 0, 9.82 };
		world = std::make_unique<b2World>(gravity);
	}

	void PhysicsSystem::Shutdown()
	{

	}

	void PhysicsSystem::Update()
	{

	}
}
