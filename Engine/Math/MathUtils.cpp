#include "MathUtils.h"

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