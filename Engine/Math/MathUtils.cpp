#include "MathUtils.h"

float en::radians(float degrees)
{
	return degrees * (pi / 180);
}

float en::degrees(float radians)
{
	return radians * (180 / pi);
}

int en::sqr(int i)
{
	return i * i;
}

int en::halfof(int i)
{
	return i / 2;
}

float en::abs(float i)
{
	if (i < 0) return -(i);

	return i;
}