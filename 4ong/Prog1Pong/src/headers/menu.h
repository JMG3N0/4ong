#pragma once


 enum Menu
{
	 Title = 0, Main, Game, Pause, Post, Credits
};

 extern Menu screens;

 Menu UpdateState(int option);
 void TitleScreen();
 void MainMenu();
 void SelectScreen();
 void PauseGame();
 void GameEnd();

