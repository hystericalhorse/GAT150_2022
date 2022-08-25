#ifndef _COMPONENT_PLAYER_H
#define _COMPONENT_PLAYER_H

#include "Framework/Component.h"
#include "Physics/Collidable.h"
#include "Math/Vector2.h"

namespace en
{
	class InputSystem;

	class PlayerComponent : public Component, public Collidable
	{
	public:
		PlayerComponent() = default;
		~PlayerComponent() = default;

		void Init() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void OnCollisionBegin(Actor* other) override;
		void OnCollisionEnd(Actor* other) override;

	public:
		float _max_velocity = 0.0f;

	};
}

#endif // _COMPONENT_PLAYER_H