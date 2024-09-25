#pragma once
#include "player.h"
#include "ball.h"

 enum Menu
{
	 Title = 0, Main, Game, Pause, Post, Credits
};
 
 extern Menu screens;

 Menu UpdateState(int& numb, float frames, struct Player* P, int& menuChoice, Ball& ball);
 void TitleScreen();
 void MainMenu();
 //void SelectScreen();
// void PauseGame();
// void GameEnd();

