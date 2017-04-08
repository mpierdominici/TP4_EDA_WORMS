#include "worms.h"
#include <iostream>


void worm ::setLookingWorm (bool Quest)
{
	lookingRight = Quest;
}

point worm::getPosition()							
{
	return p;
}

wormState worm::getWormState()
{
	return IamDoing;
}

unsigned long int worm::getFrameCount()
{
	return frameCount;
}



bool worm::lookRight()
{
	return lookingRight;
}

void worm::StopALL()
{
	IamDoing = STILL;
	frameCount = 0;
}


void worm::startJumping()
{
	IamDoing = JUMPING;

	frameCount++;
}

void worm::stopJumping()
{
	if (frameCount >= 32)
	{
	IamDoing = STILL;
	frameCount = 0;
	}
}

void worm::startMoving()
{
	if (!(IamDoing == WARMING_UP || IamDoing == WALKING || IamDoing == FINISHING_WALKING))
	{
		IamDoing = WARMING_UP;
		frameCount++;
	}
	
}
void worm::stopMoving()
{
	if (frameCount >= 50)
	{
		IamDoing = STILL;
		frameCount = 0;
	}
}

void worm::continueAction()									
{
	switch (IamDoing)
	{
		case STILL:											//If the worm is Still, just the FRAME 1 has to be drawn////In this state, the worm, does not move and does nothing. Just wait to an event//
			break;
		
		case WARMING_UP:									//Starts to walk but does not move yet, just warms up//
			if (frameCount<=8)								//A Worm can get to this state, when the key is pressed more than 100 ms. It takes three frames to start moving//															
				frameCount ++;
			else
				IamDoing = WALKING;							//If the frameCount is bigger than 8, means that the worm has to move across the X axis and is really walking//
			break;
		
		case WALKING:										//The worm is really moving, after the warming UP. Every 14 frames, the X position of the worm changes by 9.0 px//
			if (frameCount <= 22)							//9.0 Pixels times 3 cicles, represents the 27 px that the worms moves walking//
			{
				if (frameCount == 22)
				{
					if (lookingRight)						//It depends where the worm is walking if increases their position or decreases//
						p.setX (p.getX() + 9.0);
					else
						p.setX (p.getX() - 9.0);
				}
				frameCount ++;
			}
			else if (frameCount>=23 && frameCount <=36)
			{
				if (frameCount == 36)
				{
					if (lookingRight)
						p.setX (p.getX() + 9.0);
					else
						p.setX (p.getX() - 9.0); 

					IamDoing = FINISHING_WALKING;
				}
				frameCount++;
			}
			break;

		//This state represents when the worm is finishing walking and if gets 50 frames means it has finished its movement//
		
		case FINISHING_WALKING:								
			if (frameCount <=50)
			{
				if (frameCount == 50)
				{
					stopMoving();							//The worm comes back to the STILL state//
					if (lookingRight)
						p.setX (p.getX() + 9.0);
					else
						p.setX (p.getX() - 9.0); 
				}
			}
				
				frameCount++;
			break;

		//This state represents when the worm is jumping and going up//

		case JUMPING:											//Fly time of one jump is given by 32.47 FR, so we used 32 FR//
			if (lookRight())										//If is looking Right, the movement along X Axis is positive//
				p.setX(p.getX () +  2.28);						//Every frame,the position X increases 2,28 px. At the end of 32 FR, the worm would have moved 73 px across X//
			else
				p.setX(p.getX () -  2.28);						//If is looking Left, the movement along X Axis is negative//

			if (frameCount<=16)									//When the Frame Counter is smaller than 16, means the worm is going up//
				{
					p.setY(p.getY() +  2.0);						//Every frame, the position Y, when is going up increases 2 px//
					if (frameCount == 16)						//16 Frames of fly time multiplied by 2 px along Y axis, represents the Maximum height of 32 px more than 616 px//
						IamDoing = FINISHING_JUMPING;
				}
			frameCount++;
			break;
		
		//This state represents when the worm is jumping and going down//
		case FINISHING_JUMPING:
			if (lookRight())										//If is looking Right, the movement along X Axis is positive//
				p.setX(p.getX () + 2.28);						//Every frame,the position X increases 2,28 px. At the end of 32 FR, the worm would have moved 73 px across X//
			else
				p.setX(p.getX () - 2.28);						//If is looking Left, the movement along X Axis is negative//

			if (frameCount<=32)									//When the Frame Counter is smaller than 16, means the worm is going up//
				{
					p.setY(p.getY() -  2.0);					//Every frame, the position Y, when is going down decreases 2 px//
					if (frameCount == 32)						//When the entire fly time has passed, it means the worm is now at 616 px//
						stopJumping();							//From state JUMPING, the worm reaches 648 px. In this state, comes back to 616 px//
				}
			frameCount++;
			break;
	}

}