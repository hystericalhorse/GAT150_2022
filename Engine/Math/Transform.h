#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "Vector2.h"

namespace en
{
	struct Transform
	{
		Transform() = default;
		Transform(const Vector2& pos, float rot, float sca) :
			position{pos}, rotation{rot}, scale{sca}
		{}
		Vector2 position;
		float rotation = 0.0f;
		float scale = 1.0f;
	};
}

#endif // _TRANSFORM_H