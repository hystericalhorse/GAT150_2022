#ifndef _MATH_UTILS_H
#define _MATH_UTILS_H

namespace en
{
	constexpr float pi = 3.14159265359f;
	constexpr float two_pi = 6.28318530718f;
	constexpr float half_pi = 1.57079632679f;

	constexpr float radians(float degrees)
	{
		return degrees * (pi / 180);
	}

	constexpr float degrees(float radians)
	{
		return radians * (180 / pi);
	}

	int sqr(int i);
	int halfof(int i);

	float abs(float i);
}

#endif // _MATH_UTILS_H