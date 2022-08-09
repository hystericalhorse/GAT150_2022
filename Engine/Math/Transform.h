#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "Vector2.h"
#include "Matrix2x2.h"

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
		float rotation = 0.0f; // rotation in degrees

		operator Matrix2x2 () const
		{
			Matrix2x2 mxS = Matrix2x2::scale(scale);
			Matrix2x2 mxR = Matrix2x2::rotate(en::radians(rotation));

			return { mxS * mxR };
		}
	};
}

#endif // _TRANSFORM_H