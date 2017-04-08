#ifndef Point_h
#define Point_h
#include <iostream>
#define MAX_X (1212-701)
#define MAX_Y 616

//////////// clase Point //////////

class point
{
private:
	double x;
	double y;

public:

	point(){
	x = 0.0;
	y = 0.0;
	}

	point(double _x, double _y){
	
	x = _x;
	y = _y;
	}

	double getX();										 // Getter for x
	double getY();										 // Getter for y

	void setX(double _x);								 // Setter for x
	void setY(double _y);								// Setter for y

};

#endif // Point_h 