#ifndef _GAME_OBJECT_H
#define _GAME_OBJECT_H
#include "../Math/Transform.h"

namespace en
{
	class GameObject
	{
	public:
		GameObject() = default;
		GameObject(const Transform& transform) :
			_transform{ transform }
		{}
		~GameObject() = default;

		virtual void Update() = 0;

	protected:
		Transform _transform;

	private:


	};
}

#endif // _GAME_OBJECT_H