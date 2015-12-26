#include "GameManager.h"
#include <iostream>

using namespace std;
using namespace tictactoe;

Player *players;
int playerCount;
Board board;

Player* tictactoe::getPlayers()
{
	return players;
}

int tictactoe::getPlayerCount()
{
	return playerCount;
}

Board tictactoe::getBoard()
{
	return board;
}

void tictactoe::initGame()
{
	players = new Player[MAX_PLAYER_COUNT];

	bool keepAddingPlayer = true;

	while (keepAddingPlayer)
	{
		addPlayer();

		if (playerCount < MIN_PLAYER_COUNT) continue;
		if (playerCount >= MAX_PLAYER_COUNT) break;

		char answer;
		cout << "Add one more player? (Y/N): ";
		cin >> answer;
		cout << endl;
		keepAddingPlayer = answer == 'Y';
	}

	createBoard();
}

char tictactoe::getInput()
{
	for (int i = 0; i < playerCount; i++)
	{
		Player current = players[i];
		cout << endl << current.getName() << "'s Turn" << endl;

		bool invalid = true;

		while (invalid)
		{
			int x;
			cout << endl << "Move X: ";
			cin >> x;

			int y;
			cout << endl << "Move Y: ";
			cin >> y;

			cout << endl;

			x--;
			y--;

			if (
				x < 0 || x >= board.getWidth() ||
				y < 0 || y >= board.getHeight() ||
				board.get(x, y) != EMPTY)
			{
				cout << "Invalid coordinates!" << endl;
				invalid = true;
			}

			else
			{
				board.set(x, y, current.getCharacter());
				invalid = false;

				board.print();

				char winner = board.winner();
				if (winner != EMPTY) return winner;
			}
		}
	}

	return EMPTY;
}

void tictactoe::addPlayer()
{
	string playerName;
	cout << "New Player's Name: ";
	cin >> playerName;
	cout << "Hello " << playerName << "! Wich character do you want to use?" << endl;
		
	char playerCharacter;
	bool unique = false;

	while (!unique)
	{
		cout << "Character: ";
		cin >> playerCharacter;
		cout << endl;

		for (int i = 0; i < MAX_PLAYER_COUNT; i++)
		{
			Player playerI = players[i];

			if (playerI.getCharacter() == playerCharacter)
			{
				unique = false;
				cout << "I'm sorry " << playerName << ", but this character is taken!" << endl;
				break;
			}
		}

		unique = true;
	}

	players[playerCount] = Player(playerName, playerCharacter);
	playerCount++;
}

void tictactoe::createBoard()
{
	int width;
	cout << "Board Width: ";
	cin >> width;

	int height;
	cout << "Board Height: ";
	cin >> height;

	int amount;
	cout << "Amount to Win: ";
	cin >> amount;

	char diagonal;
	cout << "Diagonal Win (Y/N): ";
	cin >> diagonal;
	cout << endl;

	board = Board(width, height, amount, diagonal == 'Y');

	cout << "Board created!" << endl;
	cout << "Width: " << board.getWidth() << endl;
	cout << "Height: " << board.getHeight() << endl;
	cout << "Amount to Win: " << board.getAmount() << endl;
	cout << "Diagonal Win: " << board.getDiagonal() << endl;

	board.print();
}
