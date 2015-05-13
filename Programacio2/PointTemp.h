#ifndef _POINT_T_H_
#define _POINT_T_H_
#include<cmath>
template<class TYPE>
class Point{
public:
	TYPE x;
	TYPE y;

	Point operator -(const Point a){
		Point tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	};
	Point operator +(const Point & a){
		Point tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	};

	Point operator +=(const Point & a){
		x += a.x;
		y += a.y;
		return(*this);

	};
	Point operator -=(const Point & a){
		x -= a.x;
		y -= a.y;
		return(*this);
	};

	const bool operator ==(const Point & a){
		if (x == a.x && y == a.y)
			return true;
		else
			return false;

	};
	const bool operator !=(const Point & a){
		if (x != a.x || y != a.y)
			return true;
		else
			return false;
	};
	//Methods
	const bool IsZero(){
		if (x == 0.0f && y == 0.0f){
			return true;
		}
		else{
			return false;
		}
	}
	void SetZero(){
		x = 0;
		y = 0;
	}
	TYPE DistanceTo(Point<TYPE> & p2){
		//Vector module formula
		TYPE fx, fy;
		TYPE value;
		
		fx = pow((x - p2.x), 2.0);
		fy = pow((y - p2.y), 2.0);
		value =  sqrtl (fx + fy);
		return value;
	}
};
#endif // _POINT_T_H_