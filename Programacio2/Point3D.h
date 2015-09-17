#ifndef _POINT_3D_H_
#define _POINT_3D_H_
#include <math.h>

template<class T>
class Point3D
{
public:
	T x, y, z;

	Point3D()
	{
		x = y = z = 0;
	}
	~Point3D();

	void SetToZero()
	{
		x = y = z = 0;
	}

	template<> float Point3D<int>::GetDistance(const Point3D <T> & p)
	{
		return (float)sqrt(pow((x + p.x), 2) + pow((y + p.y), 2) + pow((z + p.z), 2));
	}

	//Raro
	double GetDistance(const Point3D <double> & p)
	{
		return sqrt(pow((x + p.x), 2) + pow((y + p.y), 2) + pow((z + p.z), 2));
	}


	float GetDistanceFromZero()
	{
		return (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	Point3D operator +(const Point3D & p)
	{
		Point3D tmp;
		tmp.x = x + p.x;
		tmp.y = y + p.y;
		tmp.z = z + p.z;
		return tmp;
	}

	Point3D operator -(const Point3D & p)
	{
		Point3D tmp;
		tmp.x = x - p.x;
		tmp.y = y - p.y;
		tmp.z = z - p.z;
		return tmp;
	}

	Point3D operator =(const Point3D & p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
		return (*this);
	}

	Point3D operator +=(const Point3D & p)
	{
		x += p.x;
		y += p.y;
		z += p.z;
		return (*this);
	}

	Point3D operator -=(const Point3D & p)
	{
		x -= p.x;
		y -= p.y;
		z -= p.z;
		return (*this);
	}
	bool operator ==(const Point3D & p)
	{
		return (x == p.x && y == p.y && z == p.z);
	}
	
	bool operator !=(const Point3D & p)
	{
		return (x == p.x && y == p.y && z == p.z ? false : true);
	}

	bool isZero()
	{
		return (x == 0 && y == 0 && z == 0);
	}
};


#endif // !_POINT_3D_H_