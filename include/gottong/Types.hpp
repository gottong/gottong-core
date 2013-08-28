#ifndef __GOTTONG_TYPES_HPP__
#define __GOTTONG_TYPES_HPP__

namespace Gottong {

template<typename T>
class Vector2 {
public:
	T x;
	T y;

public:
	Vector2(T v) : x(v), y(v) {};
	Vector2(T x, T y) : x(x), y(y) {};
};

typedef Vector2<float>	Vector2f;
typedef Vector2<int>	Vector2i;

} /* namespace Gottong */

#endif /* __GOTTONG_TYPES_HPP__ */

