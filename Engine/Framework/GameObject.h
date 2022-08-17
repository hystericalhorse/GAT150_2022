#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);

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