#ifndef _COMPONENT_COLLISION_H
#define _COMPONENT_COLLISION_H

#include "Framework/Component.h"
#include "Physics/Collidable.h"
#include "Physics/PhysicsSystem.h"

#include <functional>

namespace en
{
	class CollisionComponent : public Component, public Collidable
	{
	public:
		using actorptr = std::function<void(Actor*)>;

	public:
		CollisionComponent() = default;

		void Init() override;
		void Update() override;

		bool Write(const rapidjson::Value& value) const override;
		bool Read(const rapidjson::Value& value) override;

		void OnCollisionBegin(Actor* other) override;
		void OnCollisionEnd(Actor* other) override;

		void setCollisionEnter(actorptr function) { _enterFunction = function; }
		void setCollisionExit(actorptr function) { _exitFunction = function; }

	private:
		PhysicsSystem::CollisionDat data;
		actorptr _enterFunction;
		actorptr _exitFunction;

	};
}

#endif // _COMPONENT_COLLISION_H