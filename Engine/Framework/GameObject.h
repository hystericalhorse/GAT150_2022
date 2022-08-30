#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

#define CLONE(class) std::unique_ptr<en::GameObject> Clone() override { return std::make_unique<class>(*this); }
#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);

namespace en
{
	class GameObject
	{
	public:
		GameObject() = default;
		~GameObject() = default;

		virtual std::unique_ptr<GameObject> Clone() = 0;

		virtual void Init() = 0;
		virtual void Update() = 0;
	};
}

#endif // _GAME_OBJECT_H