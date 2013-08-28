#ifndef __GOTTONG_TYPES_HPP__
#define __GOTTONG_TYPES_HPP__

namespace Gottong {

template<typename T>
class Vector2 {
public:
	const T x;
	const T y;

public:
	Vector2(T v) : x(v), y(v) {};
	Vector2(T x, T y) : x(x), y(y) {};
};

typedef Vector2<float>	Vector2f;
typedef Vector2<int>	Vector2i;

template<typename T>
class Rect {
public:
	const T x1;
	const T y1;

	const T x2;
	const T y2;

	const T w;
	const T h;

public:
	Rect(const Vector2<T> &p1, const Vector2<T> &p2)
		: x1(p1.x), y1(p1.y), x2(p2.x), y2(p2.y), w(p2.x - p1.x), h(p2.y - p1.y) {};
	Rect(const Vector2<T> &p1, const T w, const T h)
		: x1(p1.x), y1(p1.y), x2(p1.x + w), y2(p1.y + h), w(w), h(h) {};
};

typedef Rect<float>	rectf;
typedef Rect<int>	recti;

} /* namespace Gottong */

#endif /* __GOTTONG_TYPES_HPP__ */

