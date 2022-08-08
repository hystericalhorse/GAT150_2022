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

	public:
		float _max_velocity = 200.0f;

	};
}

#endif // _COMPONENT_PLAYER_H