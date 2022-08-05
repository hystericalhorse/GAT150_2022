#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "GameObject.h"
#include "Actor.h"

namespace en
{
	class Component : public GameObject
	{
	public:
		Component() = default;
		~Component() = default;

		virtual void Update() = 0;

		friend class Actor;
	protected:
		Actor* _owner = nullptr;

	};
}

#endif // _COMPONENT_H