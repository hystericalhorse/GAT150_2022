#ifndef _PHYSICS_SYSTEM_H
#define _PHYSICS_SYSTEM_H

#include "b2_world.h"
#include <memory>

namespace en
{
	class PhysicsSystem
	{
	public:
		PhysicsSystem() = default;
		~PhysicsSystem() = default;

		void Init();
		void Shutdown();

		void Update();

	private:
		std::unique_ptr<b2World> world;


	};
}

#endif // _PHYSICS_SYSTEM_H