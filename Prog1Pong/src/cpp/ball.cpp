#include "ball.h"
#include "global.h"



 Ball setBall()
{
	Ball ball;
	ball.initPosX = (ScreenWidth/2);
	ball.initPosY = (ScreenHeight/2);
	ball.posX = ball.initPosX;
	ball.posY = ball.initPosY;
	ball.radius = 30;
	ball.lastCol = { };
	ball.initSpeed = 10;
	ball.speed = ball.initSpeed;
	

	return ball;
}