#include "sl.h"
#include "menu.h"
#include "player.h"
#include "global.h"
#include "ball.h"


int main()
{
	int playerNumb = 2;
	int menuChoice = 1;
	float frames = 0.0f;
	Player Players[4];
	Ball ball = setBall();
	slWindow(ScreenWidth, ScreenHeight, "4ong", false);
	slSetFont(slLoadFont("res/white_rabbit.ttf"), 24);
	slSetTextAlign(SL_ALIGN_CENTER);


	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		screens = UpdateState(playerNumb, frames, Players, menuChoice, ball);
	
		slRender();
		frames++;
	}

	slClose();
	return 0;
}