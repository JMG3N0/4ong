#include "menu.h"
#include "raylib.h"
#include "global.h"

Menu screens;



Menu UpdateState(int option)
{
	int MouseX = GetMouseX();
	int MouseY = GetMouseY();

	switch (screens)
	{
	case Title:
		if (IsKeyPressed(KEY_ENTER))
		{
			screens = Main;
			return screens;
		}
		break;
	case Main:

		if (MouseX >= (ScreenWidth / 2) && MouseX <= ((ScreenWidth / 2) + 10))
		{

			if (IsMouseButtonPressed)
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

	
	ClearBackground(BLACK);


	DrawText("4ong", (ScreenWidth / 2), (ScreenHeight / 2), 40, WHITE);
	DrawText("Press Enter to continue", (ScreenWidth / 2), ((ScreenHeight / 2)+10), 20, WHITE);
	screens = UpdateState(0);
}

void MainMenu()
{


	ClearBackground(BLACK);


	DrawText("4ong", (ScreenWidth / 2), (ScreenHeight / 2), 40, WHITE);
	DrawText("Play", (ScreenWidth / 2), ((ScreenHeight / 2) + 10), 20, WHITE);
	DrawText("Credits", (ScreenWidth / 2), ((ScreenHeight / 2) + 20), 20, WHITE);
	DrawText("Exit Game", (ScreenWidth / 2), ((ScreenHeight / 2) + 30), 20, WHITE);

	
	screens = UpdateState(0);

	
}
