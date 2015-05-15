#ifndef _CIRCLE_H_
#define  _CIRCLE_H_
#include "PointTemp.h"
template <class TYPE>
class Circle
{
public:
	Point <TYPE> position;
	TYPE radious;

	Circle()
	{
		position.x = position.y = 0;
		radious = 0;
	}
	Circle(const TYPE& _x, const TYPE& _y, const TYPE& _rad)
	{
		position.x = _x;
		position.y = _y;
		radious = _rad;
	}
	TYPE Area() const
	{
		return 3.14159f * (radious * radious);
	}
	bool Intersects(const Circle & ref) const
	{
		TYPE distance_X = position.x - ref.position.x;
		TYPE distance_Y = position.y - ref.position.y;
		TYPE total_radious = radious + ref.radious;

		if (distance_X <= total_radious && distance_Y <= total_radious)
			return true;
		else
			return false;
	}
};
#endif // _CIRCLE_H_