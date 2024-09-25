#include "player.h"
#include "ball.h"
#include "menu.h"

Menu StartGame(int PlayerNumb, struct Player* P, Ball& ball)
{
	Player players[4];
	Ball ballCopy = ball;
	int CollisionResult = 0;

	for (int i = 0; i < PlayerNumb; i++)
	{
		players[i] = P[i];
	}

	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	for (int y = 0; y < PlayerNumb; y++)
	{
		if (players[y].team == 1)
		{
			slSetForeColor(1.0, 0.0, 0.0, 1.0);
		}
		else if (players[y].team == 2)
		{
			slSetForeColor(0.0, 0.0, 1.0, 1.0);
		}
		slRectangleFill(players[y].posX, players[y].posY, players[y].width, players[y].height);
		slSetForeColor(1.0, 1.0, 1.0, 1.0);

		CollisionResult = ColissionPB(players[y], ballCopy);
		switch (CollisionResult)
		{
		case 1:
			ballCopy.posX +=   
				break;
		case 2:

			break;
		default:
			break;
		}
	}

	slRectangleFill(ball.posX, ball.posY, ball.width, ball.height);

	

	ball = ballCopy;
	return Post;
}

