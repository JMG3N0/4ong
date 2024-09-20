#pragma once


 enum Menu
{
	 Title = 0, Main, Game, Pause, Post, Credits
};
 
 extern Menu screens;

 Menu UpdateState(int& numb);
 void TitleScreen();
 void MainMenu();
 //void SelectScreen();
// void PauseGame();
// void GameEnd();

