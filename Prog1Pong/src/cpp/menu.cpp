#include "menu.h"
#include "global.h"





Menu screens = Title;
Menu StartGame(int PlayerNumb, struct Player* P, Ball& ball);

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

Menu UpdateState(int& numb, float frames, struct Player* P, int& menuChoice, Ball& ball)
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
		switch (menuChoice)
		{
		case 1:
			numb = PlayerNumb(numb, frames);
			if (slGetKey(SL_KEY_ENTER))
			{
				menuChoice = 2;
			}
			break;
		case 2:
			
			P = PlayerTeams(P, numb, frames);
			
			if (slGetKey(SL_KEY_ENTER) && P[0].hitPoints > 0)
			{
				menuChoice = 3;
			}
			break;
		case 3:
			screens = StartGame(numb, P, ball);
			break;
		default:
			break;
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
