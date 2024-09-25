#pragma once


struct Ball
{
	int initPosY;
	int posY;
	int initPosX;
	int posX;
	int lastCol{};
	int width;
	int height;
	float speedY;
	float speedX;
	float initSpeed;
};



Ball setBall();
