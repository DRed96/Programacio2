#ifndef _POINT_H_
#define _POINT_H_
#include<math.h>
class Point{
public:
	float x;
	float y;

	Point operator -(const Point a);
	Point operator +(const Point & a);

	Point operator +=(const Point & a);

	Point operator -=(const Point & a);

	const bool operator ==(const Point & a);

	const bool operator !=(const Point & a);
	const bool IsZero();
	void SetZero();
	float Point::DistanceTo(Point & p1, Point & p2);
};
#endif // _POINT_H_