#ifndef _COMPONENT_PLAYER_H
#define _COMPONENT_PLAYER_H

#include "Framework/Component.h"

namespace en
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		void Update() override;

	};
}

#endif // _COMPONENT_PLAYER_H