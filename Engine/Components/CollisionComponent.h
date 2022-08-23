#ifndef _COMPONENT_COLLISION_H
#define _COMPONENT_COLLISION_H

#include "Framework/Component.h"
#include "Physics/Collidable.h"
#include "Physics/PhysicsSystem.h"

namespace en
{
	class CollisionComponent : public Component, public Collidable
	{
	public:
		CollisionComponent() = default;

		void Update() override;

		bool Write(const rapidjson::Value& value) const override;
		bool Read(const rapidjson::Value& value) override;

		void OnCollisionBegin(Actor* other) override;
		void OnCollisionEnd(Actor* other) override;

	private:
		PhysicsSystem::CollisionDat data;

	};
}

#endif // _COMPONENT_COLLISION_H