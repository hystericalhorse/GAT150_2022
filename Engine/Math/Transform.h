#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "Vector2.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "MathUtils.h"

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

		/******************* Legacy ******************
		operator Matrix2x2 () const
		{
			Matrix2x2 mxS = Matrix2x2::scale(scale);
			Matrix2x2 mxR = Matrix2x2::rotate(en::radians(rotation));

			return { mxS * mxR };
		}
		*********************************************/

		operator Matrix3x3 () const
		{
			Matrix3x3 mxS = Matrix3x3::scale(scale);
			Matrix3x3 mxR = Matrix3x3::rotate(en::radians(rotation));
			Matrix3x3 mxT = Matrix3x3::translate(position);

			return { mxS * mxR * mxT };
		}
	};
}

#endif // _TRANSFORM_H