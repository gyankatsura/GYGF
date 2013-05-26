#include "MathUtil.h"
using namespace math_util;

const int& max(const int& x, const int& y)
{
	return (x > y) ? x : y;
}

const int& min(const int& x, const int& y)
{
	return (x > y) ? y : x;
}

const float& max(const float& x, const float& y)
{
	return (x > y) ? x : y;
}

const float& min(const float& x, const float& y)
{
	return (x > y) ? y : x;
}