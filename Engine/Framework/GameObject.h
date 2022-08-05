#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H
#include "Math/Transform.h"

namespace en
{
	class GameObject
	{
	public:
		GameObject() = default;
		~GameObject() = default;

		virtual void Update() = 0;
	};
}

#endif // _GAME_OBJECT_H