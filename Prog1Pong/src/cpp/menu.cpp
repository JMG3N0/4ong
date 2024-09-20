#include "menu.h"
#include "global.h"
#include "sl.h"
#include <string>
#include <iostream>

Menu screens = Title;
Menu StartGame(int PlayerNumb);

using namespace std;


void TitleScreen()
{

	slSetBackColor(0.0,0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSetFontSize(24);
	slText(((ScreenWidth / 2)- 50), (ScreenHeight / 2), "4ong");
	slSetFontSize(14);
	slText(((ScreenWidth / 2)-50), ((ScreenHeight / 2) - 50), "Press Enter to continue");
	
	
}

void MainMenu()
{
	
	
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSetFontSize(24);
	slText(((ScreenWidth / 2) - 50), (ScreenHeight / 2), "4ong");


	slSetFontSize(14);
	if (slGetMouseY() >= ((ScreenHeight / 2) - 25) && slGetMouseY() <= ((ScreenHeight / 2) -10) && slGetMouseX() >= ((ScreenWidth / 2) - 70) && slGetMouseX() <= ((ScreenWidth / 2) ))
	{

		slText((ScreenWidth / 2) - 60, ((ScreenHeight / 2) - 20), "> Play");

	}
	else
	{
		slText((ScreenWidth / 2) - 50, ((ScreenHeight / 2) - 20), "Play");
	}
	
	if (slGetMouseY() >= ((ScreenHeight / 2) - 40) && slGetMouseY() <= ((ScreenHeight / 2) - 30) && slGetMouseX() >= ((ScreenWidth / 2) - 70) && slGetMouseX() <= ((ScreenWidth / 2)))
	{

		slText((ScreenWidth / 2) - 60, ((ScreenHeight / 2) - 35), "> Credits");

	}
	else
	{
		slText((ScreenWidth / 2)-50, ((ScreenHeight / 2) - 35), "Credits");
	}
	
	if (slGetMouseY() >= ((ScreenHeight / 2) - 55) && slGetMouseY() <= ((ScreenHeight / 2) - 45) && slGetMouseX() >= ((ScreenWidth / 2) - 70) && slGetMouseX() <= ((ScreenWidth / 2)))
	{

		slText((ScreenWidth / 2) - 60, ((ScreenHeight / 2) - 50), "> Exit Game");

	}
	else
	{
		slText((ScreenWidth / 2)-50, ((ScreenHeight / 2) - 50), "Exit Game");
	}
	

	
	


	
}

int PlayerNumb(int numb)
{
	int playerCount = numb;
	string playerCountString = to_string(playerCount);
	const char* playerCountChar = playerCountString.c_str();
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	slSetFontSize(14);
	slText((ScreenWidth / 2 - 10), ((ScreenHeight / 2) +20), "How many players are there ?");
	slSetFontSize(24);
	slText((ScreenWidth / 2) - 25, ((ScreenHeight / 2)- 15), playerCountChar);
	slText(((ScreenWidth / 2)-75), ((ScreenHeight / 2)-15),"<");
	slText(((ScreenWidth / 2)+25), ((ScreenHeight / 2)-15),">");
	slSetFontSize(14);
	slText((ScreenWidth / 2)+70, ((ScreenHeight / 2) - 50), "Next");

	/*if (slGetMouseY() >= -20 && slGetMouseY() <= -10)
	{
		if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
		{
			if (playerCount > 2 && slGetMouseX() >= -80 && slGetMouseX() <= -70)
			{
				playerCount--;
			}
			else if (playerCount < 4 && slGetMouseX() >= 30 && slGetMouseX() <= 20)
			{
				playerCount++;
			}
		}
		
	}*/
	
	if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
	{
		playerCount++;
	}
	if (slGetMouseButton(SL_MOUSE_BUTTON_RIGHT))
	{
		playerCount--;
	}

	return playerCount;
	
	
	
}

Menu UpdateState(int& numb)
{
	

	switch (screens)
	{
	case Title:
		TitleScreen();
		if (slGetKey(SL_KEY_ENTER))
		{
			screens = Main;
			return screens;
		}

		break;
	case Main:

		MainMenu();
		if (slGetMouseX() >= ((ScreenWidth / 2) - 70) && slGetMouseX() <= (ScreenWidth / 2) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
		{


			if (slGetMouseY() >= ((ScreenHeight / 2) - 25) && slGetMouseY() <= ((ScreenHeight / 2) - 10))
			{
				screens = Game;

			}
			if (slGetMouseY() >= ((ScreenHeight / 2) - 40) && slGetMouseY() <= ((ScreenHeight / 2) - 30))
			{
				screens = Credits;

			}
			if (slGetMouseY() >= ((ScreenHeight / 2) - 55) && slGetMouseY() <= ((ScreenHeight / 2) - 45))
			{
				slClose();

			}




		}

		break;

	case Game:

		numb = PlayerNumb(numb);
		
		if (slGetKey(SL_KEY_ENTER))
		{
			screens = StartGame(numb);
		}
		

		break;
	case Pause:
		if (numb)
		{

		}
		break;
	case Post:
		break;
	case Credits:
		break;
	default:
		break;
	}

	return screens;

}
