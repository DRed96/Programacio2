/*#include "Point.h"
//Operators
Point Point::operator -(const Point a){
	Point tmp;
	tmp.x = x - a.x;
	tmp.y = y - a.y;
	return tmp;
};
Point Point::operator +(const Point & a){
	Point tmp;
	tmp.x = x + a.x;
	tmp.y = y + a.y;
	return tmp;
};

Point Point::operator +=(const Point & a){
	x += a.x;
	y += a.y;
	return(*this);

};
Point Point::operator -=(const Point & a){
	x -= a.x;
	y -= a.y;
	return(*this);
};

const bool Point::operator ==(const Point & a){
	if (x == a.x && y == a.y)
		return true;
	else
		return false;

};
const bool Point::operator !=(const Point & a){
	if (x != a.x || y != a.y)
		return true;
	else
		return false;
};
//Methods
const bool Point::IsZero(){
	if (x == 0.0f && y == 0.0f){
		return true;
	}
	else{
		return false;
	}
}
void Point::SetZero(){
	x = 0.0f;
	y = 0.0f;
}
TYPE Point::DistanceTo(, Point & p2){
	//Vector module formula
	TYPE fx, fy;
	x = pow((x - p2.x), 2.0f);
	y = pow((p1.y - p2.y), 2.0f);
	return sqrt(x + y);
}*/