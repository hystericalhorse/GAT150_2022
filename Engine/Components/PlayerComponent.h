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

		CLONE(PlayerComponent)

		void Init() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void OnCollisionBegin(Actor* other) override;
		void OnCollisionEnd(Actor* other) override;

	public:
		float _speed = 10.0;
		float _jump_multiplier = 1.0;

	};
}

#endif // _COMPONENT_PLAYER_H