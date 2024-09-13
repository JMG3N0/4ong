#include "sl.h"
#include "menu.h"
#include "player.h"
#include "global.h"


int main()
{
	
	slWindow(ScreenWidth, ScreenHeight, "4ong", false);
	slSetFont(slLoadFont("white_rabbit.ttf"), 24);
	slSetTextAlign(SL_ALIGN_CENTER);

	while (!slShouldClose() && !slGetKey(SL_KEY_ESCAPE))
	{
		screens = UpdateState(0);
	
		slRender();
	}

	slClose();
	return 0;
}