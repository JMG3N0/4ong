#include "ball.h"
#include "global.h"



 Ball setBall()
{
	Ball ball;
	ball.initPosX = (ScreenWidth/2);
	ball.initPosY = (ScreenHeight/2);
	ball.posX = ball.initPosX;
	ball.posY = ball.initPosY;
	ball.width = 20;
	ball.height = 20;
	ball.lastCol = { };
	ball.initSpeed = 10;
	ball.speedY = ball.initSpeed;
	ball.speedX = ball.initSpeed;
	

	return ball;
}