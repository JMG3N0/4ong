#include "menu.h"
#include "global.h"
#include "sl.h"

Menu screens = Title;



Menu UpdateState(int option)
{
	

	switch (screens)
	{
	case Title:
		if (slGetKey(SL_KEY_ENTER))
		{
			screens = Main;
			return screens;
		}
		break;
	case Main:

		if (MouseX >= (ScreenWidth / 2) && MouseX <= ((ScreenWidth / 2) + 10))
		{

			if (slGetMouseButton(SL_MOUSE_BUTTON_LEFT))
			{
				if (MouseY >= ((ScreenHeight / 2) + 10) && MouseY <= ((ScreenHeight / 2) + 15))
				{
					screens = Game;
					return screens;
				}
				if (MouseY >= ((ScreenHeight / 2) + 20) && MouseY <= ((ScreenHeight / 2) + 25))
				{
					screens = Credits;
					return screens;
				}
				if (MouseY >= ((ScreenHeight / 2) + 30) && MouseY <= ((ScreenHeight / 2) + 25))
				{
					EndDrawing();
					CloseWindow();
					
				}


			}

		}
		
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
	InitWindow(ScreenWidth, ScreenHeight, "4ong");
	BeginDrawing();
	ClearBackground(BLACK);

	screens = UpdateState(0);
	DrawText("4ong", (ScreenWidth / 2), (ScreenHeight / 2), 40, WHITE);
	DrawText("Press Enter to continue", (ScreenWidth / 2), ((ScreenHeight / 2)+10), 20, WHITE);
	
}

void MainMenu()
{


	ClearBackground(BLACK);


	DrawText("4ong", (ScreenWidth / 2), (ScreenHeight / 2), 40, WHITE);
	if (MouseY >= ((ScreenHeight / 2) + 10) && MouseY <= ((ScreenHeight / 2) + 15))
	{
		DrawText("Play", (ScreenWidth / 2), ((ScreenHeight / 2) + 10), 20, GRAY);
	}
	else
	{
		DrawText("Play", (ScreenWidth / 2), ((ScreenHeight / 2) + 10), 20, WHITE);
	}
	
	if (((ScreenHeight / 2) + 20) && MouseY <= ((ScreenHeight / 2) + 25))
	{
		DrawText("Credits", (ScreenWidth / 2), ((ScreenHeight / 2) + 20), 20, GRAY);
	}
	else
	{
		DrawText("Credits", (ScreenWidth / 2), ((ScreenHeight / 2) + 20), 20, WHITE);
	}
	
	if (((ScreenHeight / 2) + 30) && MouseY <= ((ScreenHeight / 2) + 25))
	{
		DrawText("Exit Game", (ScreenWidth / 2), ((ScreenHeight / 2) + 30), 20, GRAY);
	}
	else
	{
		DrawText("Exit Game", (ScreenWidth / 2), ((ScreenHeight / 2) + 30), 20, WHITE);
	}
	

	
	screens = UpdateState(0);

	
}

void GameDetails()
{
	int playerCount = 2;
	int teams[4] = {0,0,0,0};


	ClearBackground(BLACK);

	DrawText("How many players are gonna play ?", (ScreenWidth / 2), (ScreenHeight / 2), 30, WHITE);
}
