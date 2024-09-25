#include "player.h"
#include "global.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

Player setPlayer(int number, int team, bool alive)
{
	Player player;

	player.multiplier = 1.0f;
	player.team = team;
	player.hitPoints = 5;
	player.isAlive = alive;

	switch (number)
	{
	case 0:
		player.initPosY = (ScreenHeight / 2);
		player.initPosX = 50;
		player.height = 100;
		player.width = 50;
		break;
	case 1:
		player.initPosY = (ScreenHeight / 2);
		player.initPosX = (ScreenWidth - 50);
		player.height = 100;
		player.width = 50;
		break;
	case 2:
		player.initPosY = 50;
		player.initPosX = (ScreenHeight / 2);
		player.height = 50;
		player.width = 400;
		break;
	case 3:
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

int PlayerNumb(int numb, float frames)
{
	int playerCount = numb;
	float frameNumber = frames;
	string playerCountString = to_string(playerCount);
	const char* playerCountChar = playerCountString.c_str();
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	slSetFontSize(14);
	slText((ScreenWidth / 2 - 20), ((ScreenHeight / 2) + 20), "How many players are there ?");
	slSetFontSize(24);
	slText((ScreenWidth / 2) - 25, ((ScreenHeight / 2) - 15), playerCountChar);
	slText(((ScreenWidth / 2) - 75), ((ScreenHeight / 2) - 15), "<");
	slText(((ScreenWidth / 2) + 25), ((ScreenHeight / 2) - 15), ">");


	if (slGetMouseY() <= ((ScreenHeight / 2) + 10) && slGetMouseY() >= ((ScreenHeight / 2) - 20))
	{
		if (slGetMouseX() >= ((ScreenWidth / 2) - 90) && slGetMouseX() <= ((ScreenWidth / 2) - 70))
		{

			slSetForeColor(1.0, 0.0, 0.0, 1.0);
			slText(((ScreenWidth / 2) - 75), ((ScreenHeight / 2) - 15), "<");
			slSetForeColor(1.0, 1.0, 1.0, 1.0);

			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && remainderf(frameNumber, DeltaTime) == 0 && playerCount >= 3)
			{

				playerCount--;

			}
			else if (playerCount == 2)
			{
				slSetForeColor(0.128, 0.128, 0.128, 1.0);
				slText(((ScreenWidth / 2) - 75), ((ScreenHeight / 2) - 15), "<");
				slSetForeColor(1.0, 1.0, 1.0, 1.0);
			}
		}

		if (slGetMouseX() >= ((ScreenWidth / 2)) && slGetMouseX() <= ((ScreenWidth / 2) + 30))
		{
			slSetForeColor(0.0, 0.0, 1.0, 1.0);
			slText(((ScreenWidth / 2) + 25), ((ScreenHeight / 2) - 15), ">");
			slSetForeColor(1.0, 1.0, 1.0, 1.0);

			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && remainderf(frameNumber, DeltaTime) == 0 && playerCount < 4)
			{

				playerCount++;

			}
			else if (playerCount == 4)
			{
				slSetForeColor(0.128, 0.128, 0.128, 1.0);
				slText(((ScreenWidth / 2) + 25), ((ScreenHeight / 2) - 15), ">");
				slSetForeColor(1.0, 1.0, 1.0, 1.0);
			}
		}


	}

	slSetFontSize(14);
	slText((ScreenWidth / 2) - 20, ((ScreenHeight / 2) - 70), "(Hold the left click over the arrows)");
	slText((ScreenWidth / 2) - 20, ((ScreenHeight / 2) - 90), "(Press Enter once you have decided)");





	return playerCount;



}

Player* PlayerTeams(struct Player* P, int numb, float frames)
{
	int TeamBlue = 0;
	int TeamRed = 0;
	float FrameNumber = frames;
	bool CanReturn = false;

	slSetFontSize(14);
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slText(((ScreenWidth / 2) - 340), ((ScreenHeight / 2) - 60), "Controls:");
	slSetFontSize(24);
	for (int i = 0; i < numb; i++)
	{
		if (P[i].team == 1)
		{
			slSetForeColor(1.0, 0.0, 0.0, 1.0);
		}
		else if (P[i].team == 2)
		{
			slSetForeColor(0.0, 0.0, 1.0, 1.0);
		}
		else
		{
			slSetForeColor(1.0, 1.0, 1.0, 1.0);
		}

		switch (i)
		{
		case 0:
			slText(((ScreenWidth / 2) - 240), ((ScreenHeight / 2)), "^");
			slText(((ScreenWidth / 2) - 240), ((ScreenHeight / 2) - 15), "< P1 >");
			slText(((ScreenWidth / 2) - 240), ((ScreenHeight / 2) - 30), "_");
			slSetFontSize(14);
			if (P[i].isAlive == true)
			{
				slText(((ScreenWidth / 2) - 240), ((ScreenHeight / 2) - 60), "W/S");
			}
			else if (P[i].isAlive == false)
			{
				slText(((ScreenWidth / 2) - 240), ((ScreenHeight / 2) - 60), "CPU");
			}
			else
			{
				slText(((ScreenWidth / 2) - 240), ((ScreenHeight / 2) - 60), "W/S");
			}
			break;
		case 1:
			slSetFontSize(24);
			slText(((ScreenWidth / 2) - 80), ((ScreenHeight / 2)), "^");
			slText(((ScreenWidth / 2) - 80), ((ScreenHeight / 2) - 15), "< P2 >");
			slText(((ScreenWidth / 2) - 80), ((ScreenHeight / 2) - 30), "_");
			slSetFontSize(14);
			if (P[i].isAlive == true)
			{
				slText(((ScreenWidth / 2) - 80), ((ScreenHeight / 2) - 60), "Keypad 7/1");
			}
			else if (P[i].isAlive == false)
			{
				slText(((ScreenWidth / 2) - 80), ((ScreenHeight / 2) - 60), "CPU");
			}
			else
			{
				slText(((ScreenWidth / 2) - 80), ((ScreenHeight / 2) - 60), "Keypad 7/1");
			}
			break;
		case 2:
			slSetFontSize(24);
			slText(((ScreenWidth / 2) + 80), ((ScreenHeight / 2)), "^");
			slText(((ScreenWidth / 2) + 80), ((ScreenHeight / 2) - 15), "< P3 >");
			slText(((ScreenWidth / 2) + 80), ((ScreenHeight / 2) - 30), "_");
			slSetFontSize(14);
			if (P[i].isAlive == true)
			{
				slText(((ScreenWidth / 2) + 80), ((ScreenHeight / 2) - 60), "Arrows Up/Down");
			}
			else if (P[i].isAlive == false)
			{
				slText(((ScreenWidth / 2) + 80), ((ScreenHeight / 2) - 60), "CPU");
			}
			else
			{
				slText(((ScreenWidth / 2) + 80), ((ScreenHeight / 2) - 60), "Arrows Up/Down");
			}
			break;
		case 3:
			slSetFontSize(24);
			slText(((ScreenWidth / 2) + 240), ((ScreenHeight / 2)), "^");
			slText(((ScreenWidth / 2) + 240), ((ScreenHeight / 2) - 15), "< P4 >");
			slText(((ScreenWidth / 2) + 240), ((ScreenHeight / 2) - 30), "_");
			slSetFontSize(14);
			if (P[i].isAlive == true)
			{
				slText(((ScreenWidth / 2) + 240), ((ScreenHeight / 2) - 60), "Keypad 2/3");
			}
			else if (P[i].isAlive == false)
			{
				slText(((ScreenWidth / 2) + 240), ((ScreenHeight / 2) - 60), "CPU");
			}
			else
			{
				slText(((ScreenWidth / 2) + 240), ((ScreenHeight / 2) - 60), "Keypad 2/3");
			}
			
			break;
		default:
			break;
		}
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
		slText((ScreenWidth / 2) - 20, ((ScreenHeight / 2) - 110), "(Hold the left click over the </> arrows to select teams)");
		slText((ScreenWidth / 2) - 20, ((ScreenHeight / 2) - 130), "(Hold the left click over the ^/_ icons to select players)");
		slText((ScreenWidth / 2) - 20, ((ScreenHeight / 2) - 150), "(Press Enter once you have decided)");

		if (P[i].team == 1)
		{
			TeamRed++;
		}
		else if (P[i].team == 2)
		{
			TeamBlue++;
		}
	}

	if (TeamBlue + TeamRed == numb)
	{
		if (TeamBlue < numb && TeamRed < numb)
		{
			CanReturn = true;
		}
	}
	else
	{
		CanReturn = false;
	}

	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT) && remainderf(FrameNumber, DeltaTime) == 0)
	{
		if (slGetMouseY() <= ((ScreenHeight / 2) + 10) && slGetMouseY() >= ((ScreenHeight / 2) - 20))
		{

			if (slGetMouseX() >= ((ScreenWidth / 2) - 275) && slGetMouseX() <= ((ScreenWidth / 2) - 245))
			{
				P[0].team = 2; // blue
			}
			else if (slGetMouseX() >= ((ScreenWidth / 2) - 210) && slGetMouseX() <= ((ScreenWidth / 2) - 180))
			{
				P[0].team = 1; // red
			}

			if (slGetMouseX() >= ((ScreenWidth / 2) - 60) && slGetMouseX() <= ((ScreenWidth / 2) - 35))
			{
				P[1].team = 1;
			}
			else if (slGetMouseX() >= ((ScreenWidth / 2) - 140) && slGetMouseX() <= ((ScreenWidth / 2) - 100))
			{
				P[1].team = 2;
			}

			if (slGetMouseX() >= ((ScreenWidth / 2) + 35) && slGetMouseX() <= ((ScreenWidth / 2) + 60))
			{
				P[2].team = 2;
			}
			else if (slGetMouseX() >= ((ScreenWidth / 2) + 100) && slGetMouseX() <= ((ScreenWidth / 2) + 140))
			{
				P[2].team = 1;
			}

			if (slGetMouseX() >= ((ScreenWidth / 2) + 255) && slGetMouseX() <= ((ScreenWidth / 2) + 275))
			{
				P[3].team = 1; // blue
			}
			else if (slGetMouseX() >= ((ScreenWidth / 2) + 205) && slGetMouseX() <= ((ScreenWidth / 2) + 220))
			{
				P[3].team = 2; // red
			}

		}

		if (slGetMouseY() <= ((ScreenHeight / 2) + 20) && slGetMouseY() >= ((ScreenHeight / 2) - 5))
		{
			
				if (slGetMouseX() >= ((ScreenWidth / 2) - 260) && slGetMouseX() <= ((ScreenWidth / 2) - 220))
				{



					P[0].isAlive = true;


				}

				if (slGetMouseX() >= ((ScreenWidth / 2) - 90) && slGetMouseX() <= ((ScreenWidth / 2) - 70))
				{

					P[1].isAlive = true;

				}

				if (slGetMouseX() >= ((ScreenWidth / 2) + 70) && slGetMouseX() <= ((ScreenWidth / 2) + 90))
				{

					P[2].isAlive = true;


				}

				if (slGetMouseX() >= ((ScreenWidth / 2) + 230) && slGetMouseX() <= ((ScreenWidth / 2) + 250))
				{

					P[2].isAlive = true;


				}

			
		}
		
		if (slGetMouseY() <= ((ScreenHeight / 2) - 25) && slGetMouseY() >= ((ScreenHeight / 2) - 40))
		{
			
				if (slGetMouseX() >= ((ScreenWidth / 2) - 260) && slGetMouseX() <= ((ScreenWidth / 2) - 220))
				{



					P[0].isAlive = false;


				}

				if (slGetMouseX() >= ((ScreenWidth / 2) - 90) && slGetMouseX() <= ((ScreenWidth / 2) - 70))
				{

					P[1].isAlive = false;

				}

				if (slGetMouseX() >= ((ScreenWidth / 2) + 70) && slGetMouseX() <= ((ScreenWidth / 2) + 90))
				{

					P[2].isAlive = false;


				}

				if (slGetMouseX() >= ((ScreenWidth / 2) + 230) && slGetMouseX() <= ((ScreenWidth / 2) + 250))
				{

					P[2].isAlive = false;


				}

			
		}

	}

	if (slGetKey(SL_KEY_ENTER) && CanReturn == true)
	{
		for (int y = 0; y < numb; y++)
		{
			P[y] = setPlayer(y, P[y].team, P[y].isAlive);
		}
	}

	return P;
}

int ColissionPB(Player P, Ball ball)
{
	if (P.width == 50)
	{
		if (ball.posY >= P.posY-(P.height/2) && ball.posY <= P.posY + (P.height / 2))
		{
			if (ball.posX - (ball.width/2) <= P.posX+(P.width/2) || ball.posX + (ball.width / 2) >= P.posX - (P.width / 2))
			{
				return 1;
			}
		
		}
	}
	else if (P.width == 400)
	{
		if (ball.posX >= P.posX - (P.width/2) && ball.posX <= P.posX + (P.width / 2))
		{
			if (ball.posY - (ball.height / 2) <= P.posY + (P.width / 2) && ball.posY + (ball.height / 2) >= P.posY - (P.width / 2))
			{
				return 2;
			}
			
		}
	}

	return 0;
}