#include "ball.h"
#include "global.h"

Ball ball;

Ball setBall()
{
	ball.color = WHITE;
	ball.initPosX = (ScreenWidth/2);
	ball.initPosY = (ScreenHeight/2);
	ball.posX = ball.initPosX;
	ball.posY = ball.initPosY;
	ball.radius = 30;
	ball.lastCol = { };
	ball.speed = 10;
	

	return ball;
}