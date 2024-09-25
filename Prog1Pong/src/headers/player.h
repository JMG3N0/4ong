#pragma once
#include "sl.h"
#include "ball.h"

struct Player
{
	int posY;
	int posX;
	int initPosY;
	int initPosX;
	int height;
	int width;
	int team;
	int hitPoints;
	float multiplier;
	bool isAlive;
};

Player setPlayer(int number, int team, bool alive);
Player* PlayerTeams(struct Player* P, int numb, float frames);
int ColissionPB(Player P, Ball ball);
int PlayerNumb(int numb, float frames);


