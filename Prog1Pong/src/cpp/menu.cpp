#include "menu.h"
#include "global.h"
#include "sl.h"

Menu screens = Title;





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
		slSetForeColor(0.95, 0.95, 0.95, 1.0);
		slText((ScreenWidth / 2) - 60, ((ScreenHeight / 2) - 20), "> Play");
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	}
	else
	{
		slText((ScreenWidth / 2) - 50, ((ScreenHeight / 2) - 20), "Play");
	}
	
	if (slGetMouseY() >= ((ScreenHeight / 2) - 40) && slGetMouseY() <= ((ScreenHeight / 2) - 30) && slGetMouseX() >= ((ScreenWidth / 2) - 70) && slGetMouseX() <= ((ScreenWidth / 2)))
	{
		slSetForeColor(0.95, 0.95, 0.95, 1.0);
		slText((ScreenWidth / 2) - 60, ((ScreenHeight / 2) - 35), "> Credits");
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	}
	else
	{
		slText((ScreenWidth / 2)-50, ((ScreenHeight / 2) - 35), "Credits");
	}
	
	if (slGetMouseY() >= ((ScreenHeight / 2) - 55) && slGetMouseY() <= ((ScreenHeight / 2) - 45) && slGetMouseX() >= ((ScreenWidth / 2) - 70) && slGetMouseX() <= ((ScreenWidth / 2)))
	{
		slSetForeColor(0.95, 0.95, 0.95, 1.0);
		slText((ScreenWidth / 2) - 60, ((ScreenHeight / 2) - 50), "> Exit Game");
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	}
	else
	{
		slText((ScreenWidth / 2)-50, ((ScreenHeight / 2) - 50), "Exit Game");
	}
	

	
	


	
}

void PreGame()
{
	int playerCount = 2;
	int teams[4] = {0,0,0,0};
	char playerCountChar = static_cast<char>(playerCount);
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);

	slSetFontSize(14);
	slText((ScreenWidth / 2), ((ScreenHeight / 2) +20), "How many players are there ?");
	slSetFontSize(24);
	slText((ScreenWidth / 2), ((ScreenHeight / 2)),"playerCountChar");
	/*slText((ScreenWidth / 2), ((ScreenHeight / 2)),"<"  ">");
	slText((ScreenWidth / 2), ((ScreenHeight / 2)),"<"  ">");*/
	slSetFontSize(14);
	slText((ScreenWidth / 2)-20, ((ScreenHeight / 2) - 50), "Press Enter to continue");

	if (slGetMouseButton(SL_KEY_LEFT) && playerCount > 1)
	{
		playerCount--;
	}
	if (slGetMouseButton(SL_KEY_RIGHT) && playerCount < 4)
	{
		playerCount++;
	}

	/*if (slGetKey(SL_KEY_ENTER))
	{
		
	}*/
	
}

Menu UpdateState(int option)
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

		PreGame();

		break;
	case Pause:
		if (option)
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
