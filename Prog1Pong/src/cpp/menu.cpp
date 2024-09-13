#include "menu.h"
#include "global.h"
#include "sl.h"

Menu screens = Title;



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
		/*if (slGetMouseX() >= ((ScreenWidth / 2) + 10) && slGetMouseX() <= ((ScreenWidth / 2) - 10) && slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
		{

			
				if (slGetMouseY() >= ((ScreenHeight / 2) + 10) && slGetMouseY() <= ((ScreenHeight / 2) + 15))
				{
					screens = Game;
					return screens;
				}
				if (slGetMouseY() >= ((ScreenHeight / 2) + 20) && slGetMouseY() <= ((ScreenHeight / 2) + 25))
				{
					screens = Credits;
					return screens;
				}
				if (slGetMouseY() >= ((ScreenHeight / 2) + 30) && slGetMouseY() <= ((ScreenHeight / 2) + 25))
				{
					slClose();
					
				}


			

		}*/
		
		break;
	case Game:

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
	
}

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
	//int MouseX = slGetMouseX();
	
	
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSetFontSize(24);
	slText(((ScreenWidth / 2) - 50), (ScreenHeight / 2), "4ong");


	/*slSetFontSize(14);
	if (slGetMouseY() >= ((ScreenHeight / 2) + 10) && slGetMouseY() <= ((ScreenHeight / 2) + 15) && slGetMouseX() >= ((ScreenWidth / 2) +10) && slGetMouseX() <= ((ScreenWidth / 2) - 10))
	{
		slSetForeColor(0.95, 0.95, 0.95, 1.0);
		slText((ScreenWidth / 2), ((ScreenHeight / 2) + 10), "Play");
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	}
	else
	{
		slText((ScreenWidth / 2), ((ScreenHeight / 2) + 10), "Play");
	}
	
	if (slGetMouseY() >= ((ScreenHeight / 2) + 20) && slGetMouseY() <= ((ScreenHeight / 2) + 25) && slGetMouseX() >= ((ScreenWidth / 2) + 10) && slGetMouseX() <= ((ScreenWidth / 2) - 10))
	{
		slSetForeColor(0.95, 0.95, 0.95, 1.0);
		slText((ScreenWidth / 2), ((ScreenHeight / 2) + 20), "Credits");
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	}
	else
	{
		slText((ScreenWidth / 2), ((ScreenHeight / 2) + 20), "Credits");
	}
	
	if (slGetMouseY() >= ((ScreenHeight / 2) + 30) && slGetMouseY() <= ((ScreenHeight / 2) + 25) && slGetMouseX() >= ((ScreenWidth / 2) + 10) && slGetMouseX() <= ((ScreenWidth / 2) - 10))
	{
		slSetForeColor(0.95, 0.95, 0.95, 1.0);
		slText((ScreenWidth / 2), ((ScreenHeight / 2) + 30), "Exit Game");
		slSetForeColor(1.0, 1.0, 1.0, 1.0);
	}
	else
	{
		slText((ScreenWidth / 2), ((ScreenHeight / 2) + 30), "Exit Game");
	}*/
	

	
	


	
}

void GameDetails()
{
	int playerCount = 2;
	int teams[4] = {0,0,0,0};
	char playerCountChar = static_cast<char>(playerCount);
	slSetTextAlign(SL_ALIGN_CENTER);
	slSetBackColor(0.0, 0.0, 0.0);
	slSetForeColor(1.0, 1.0, 1.0, 1.0);
	slSetFontSize(14);
	slText((ScreenWidth / 2), ((ScreenHeight / 2) +20), "How many players are there ?");
	slSetFontSize(24);
	slText((ScreenWidth / 2), ((ScreenHeight / 2)),"<" "playerCountChar" ">");
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

	if (slGetKey(SL_KEY_ENTER))
	{
		
	}
	
}
