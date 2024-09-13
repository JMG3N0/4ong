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
		player.posY = (ScreenHeight / 2);
		player.posX = 50;
		player.height = 100;
		player.width = 100;
		break;
	case 2:
		player.posY = (ScreenHeight / 2);
		player.posX = (ScreenWidth - 50);
		player.height = 100;
		player.width = 100;
		break;
	case 3:
		player.posY = 50;
		player.posX = (ScreenHeight / 2);
		player.height = 50;
		player.width = 400;
		break;
	case 4:
		player.posY = (ScreenHeight - 50);
		player.posX = (ScreenHeight / 2);
		player.height = 50;
		player.width = 400;
		break;
	default:
		break;
	}

	

	
	return player;
}