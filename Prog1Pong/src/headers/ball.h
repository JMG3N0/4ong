#pragma once


struct Ball
{
	int initPosY;
	int posY;
	int initPosX;
	int posX;
	int lastCol{};
	float radius;
	float speed;

};

extern Ball ball;

Ball setBall();
