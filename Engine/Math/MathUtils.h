#ifndef _MATH_UTILS_H
#define _MATH_UTILS_H

namespace en
{
	const float pi = 3.14159265359f;
	const float two_pi = 6.28318530718f;
	const float half_pi = 1.57079632679f;

	float radians(float degrees);
	float degrees(float radians);

	int sqr(int i);
	int halfof(int i);

	float abs(float i);
}

#endif // _MATH_UTILS_H