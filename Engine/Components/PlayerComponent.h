#ifndef _COMPONENT_PLAYER_H
#define _COMPONENT_PLAYER_H

#include "CharacterComponent.h"
#include "Math/Vector2.h"

namespace en
{
	class InputSystem;

	class PlayerComponent : public CharacterComponent
	{
	public:
		PlayerComponent() = default;
		~PlayerComponent() = default;

		CLONE(PlayerComponent)

		void Init() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void OnCollisionBegin(Actor* other) override;
		virtual void OnCollisionEnd(Actor* other) override;

		void onNotification(const Event& event) override;

	public:
		Vector2 _direction = en::Vector2::zero;
		float _jump_multiplier = 1.0;

	};
}

#endif // _COMPONENT_PLAYER_H