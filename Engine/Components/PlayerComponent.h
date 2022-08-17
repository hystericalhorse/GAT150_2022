#ifndef _COMPONENT_PLAYER_H
#define _COMPONENT_PLAYER_H

#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace en
{
	class InputSystem;

	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;
		~PlayerComponent() = default;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		float _max_velocity = 0.0f;

	};
}

#endif // _COMPONENT_PLAYER_H