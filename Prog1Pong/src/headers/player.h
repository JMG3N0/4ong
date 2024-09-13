#pragma once
#include "sl.h"

struct Player
{
	int posY;
	int posX;
	int height;
	int width;
	int team;
	float points;
	bool multiplier;
};

Player setPlayer(int number, int team);


