#pragma once
#include "sl.h"

struct Player
{
	int posY;
	int posX;
	int initPosY;
	int initPosX;
	int height;
	int width;
	int team;
	float points;
	bool multiplier;
};

Player setPlayer(int number, int team);


