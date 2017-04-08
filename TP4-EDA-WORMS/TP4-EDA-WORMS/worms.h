#ifndef worms_h
#define worms_h

#include "point.h"
#include <time.h>

typedef enum { STILL, WARMING_UP, WALKING, JUMPING , FINISHING_JUMPING, FINISHING_WALKING ,WALKING_PENDING } wormState;


/**********************
*	WORM CLASS        *
**********************/

#define minX 701
#define maxX 1212
#define Y	0
#define TRUE 1

class worm
{
private:
	point p;												//Represents the x,y position of the worm chosen//
	bool lookingRight;										//Represents if the worm is Looking to the right or to the left//
	wormState IamDoing;										// The actual state of a worm, which could be Jumping, Walking or Still//
	unsigned long int frameCount; 							// 
															// si estoy walking o jumping me va a decir hace cuantos frame que estoy asi
															// para jumping sirve para calcular la posicion real de worm (t)
	
public:

	//Worm Constructor: Sets a random position along the X axis and the allowed part of the display//
	//Every worm initialized, starts looking to the right and without moving//
	worm()			
	{
		srand(time(NULL));
		int x =  rand() % (1212 - 701);				//int x = 701 + rand() % (1212 - 701); This can be used to place the worm in the display too//						
		p.setX(x); 
		p.setY(Y);
		lookingRight = TRUE;
		IamDoing = STILL;
		frameCount = 0;
	}

	//This function should be called, when the user presses the W or KEY UP to make the worm jump//
	void startJumping();					
	
	//This Function should be called when the right or left key is pressed more than 100 ms//
	void startMoving();						
	
	//This function has to be called all the time, to check what the actual state of the worm is//
	void continueAction();					
	
	//This function stops a worm which is moving//
	void stopMoving();						
	
	//This function stops a worm when is jumping//
	void stopJumping();

	//This function has to be called when the Right key is pressed, with a bool YES, or when the Left Key is pressed with a bool NO to set the new direction of the worm//
	void setLookingWorm (bool);

	//These functions must be used to graph the worm//
	//Using the position in the X and the Y//
	//The state of the worm and the correspondent frame of the movement//
	//Finally, if the worm is looking to the right or to the left// 
	point getPosition();							
	wormState getWormState();
	unsigned long int getFrameCount();

	bool lookRight();
	void StopALL();
};

#endif // worms_h 