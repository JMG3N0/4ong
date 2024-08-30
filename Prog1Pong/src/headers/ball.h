#pragma once
#include "raylib.h"

struct Ball
{
	int initPosY;
	int posY;
	int initPosX;
	int posX;
	int lastCol{};
	float radius;
	float speed;
	Color color;
};

extern Ball ball;

Ball setBall();
