#pragma once
#include "Player.h"
#include "Board.h"
#define MIN_PLAYER_COUNT 2
#define MAX_PLAYER_COUNT 4

namespace tictactoe
{
	Player* getPlayers();
	int getPlayerCount();
	Board getBoard();
	void initGame();
	char getInput();
	void addPlayer();
	void createBoard();
}