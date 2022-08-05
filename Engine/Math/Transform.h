#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "Vector2.h"

namespace en
{
	struct Transform
	{
		Transform() = default;
		Transform(const Vector2& pos, float rot, Vector2 sca) :
			position{pos}, rotation{rot}, scale{sca}
		{}
		Vector2 position { 0,0 };
		Vector2 scale { 1, 1 };
		float rotation = 0.0f;
	};
}

#endif // _TRANSFORM_H