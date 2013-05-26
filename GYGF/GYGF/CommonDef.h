#ifndef __COMMON_DEF_H__
#define __COMMON_DEF_H__

template<typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
};

typedef Rect<int> RectInt;
typedef Rect<float> RectFloat;

template<typename T>
struct Vector
{
	T x;
	T y;
};

typedef Vector<int> VecInt;
typedef Vector<float> VecFloat;

#endif