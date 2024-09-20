#include "sl.h"
#include "menu.h"
#include "player.h"
#include "global.h"


int main()
{
	int playerNumb = 2;

	slWindow(ScreenWidth, ScreenHeight, "4ong", false);
	slSetFont(slLoadFont("res/white_rabbit.ttf"), 24);
	slSetTextAlign(SL_ALIGN_CENTER);


	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		screens = UpdateState(playerNumb);
	
		slRender();
	}

	slClose();
	return 0;
}