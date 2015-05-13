#include "PointTemp.h"

 
class Projectile{
public:
	Point <float> pos;
	Point <float> speed;

	Projectile()
	{
		pos.x = speed.x = 0.0;
		pos.y = speed.y = 0.0;
	}

	const Point <float> GetCurrentPosition(float time)
	{
		Point<float> tmp;
		tmp.x = (speed.x * time) + pos.x;
		tmp.y = (speed.y * time) + pos.y;
		return(tmp);
	}
};