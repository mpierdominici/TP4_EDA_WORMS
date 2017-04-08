#include "point.h"

double point::getX()
{
	return x;
}


double point::getY()
{ 
	
	return y;
}


void point::setX(double _x)
{
	if (_x < 0)
	{
		x = 0;
	}
	else if (_x > (MAX_X-37))
	{
		x = MAX_X-37;

	}
	else 
	{
		x = _x;
	}
	
}


void point::setY(double _y)
{
	if (_y < 0)
	{
		y = 0;
	}
	else
	{
		y = _y;
	}
	
}