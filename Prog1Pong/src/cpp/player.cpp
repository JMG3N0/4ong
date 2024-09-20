#include "player.h"
#include "global.h"

Player setPlayer(int number, int team)
{
	Player player;

	player.multiplier = 1;
	player.team = team;
	player.points = 0.0f;

	switch (number)
	{
	case 1:
		player.initPosY = (ScreenHeight / 2);
		player.initPosX = 50;
		player.height = 100;
		player.width = 100;
		break;
	case 2:
		player.initPosY = (ScreenHeight / 2);
		player.initPosX = (ScreenWidth - 50);
		player.height = 100;
		player.width = 100;
		break;
	case 3:
		player.initPosY = 50;
		player.initPosX = (ScreenHeight / 2);
		player.height = 50;
		player.width = 400;
		break;
	case 4:
		player.initPosY = (ScreenHeight - 50);
		player.initPosX = (ScreenHeight / 2);
		player.height = 50;
		player.width = 400;
		break;
	default:
		break;
	}

	player.posX = player.initPosX;
	player.posY = player.initPosY;

	
	return player;
}