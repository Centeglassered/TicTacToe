#include "GameManager.h"
#include "Board.h"
#include "Player.h"
#include <iostream>

int main()
{
	using namespace tictactoe;
	using namespace std;

	system("TITLE Tic Tac Toe");

	initGame();

	system("PAUSE");

	char winner = EMPTY;

	while (winner == EMPTY)
	{
		winner = getInput();
	}

	if (winner == VOID)
	{
		cout << endl << "No one win, tie!" << endl;
	}

	else
	{
		Player player;

		for (int i = 0; i < getPlayerCount(); i++)
		{
			Player current = getPlayers()[i];

			if (current.getCharacter() == winner)
			{
				player = current;
				break;
			}
		}

		cout << endl << player.getName() << " wins!" << endl;
	}

	delete[] getPlayers();

	system("PAUSE");
	return 0;
}