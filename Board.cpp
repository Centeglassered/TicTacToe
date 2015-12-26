#include "Board.h"
#include <iostream>
#include <string>

using namespace tictactoe;

Board::Board(int width, int height, int amount, bool diagonal)
{
	this->width = width < MIN ? MIN : width > MAX ? MAX : width;
	this->height = height < MIN ? MIN : height > MAX ? MAX : height;
	
	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			this->board[i][j] = i < height && j < width ? EMPTY : VOID;

	this->amount = amount;
	this->diagonal = diagonal;
}

Board::Board()
{
	this->width = MIN;
	this->height = MIN;
	
	for (int i = 0; i < MAX; i++)

		for (int j = 0; j < MAX; j++)

			this->board[i][j] = i < height && j < width ? EMPTY : VOID;

	this->amount = 3;
	this->diagonal = false;
}

char Board::get(int x, int y)
{
	return this->board[y][x];
}

void Board::set(int x, int y, char c)
{
	if (
		x < 0 || x >= width ||
		y < 0 || y >= height)

		return;

	this->board[y][x] = c;
}

char Board::winner()
{
	if (amount > width) amount = width;
	if (amount > height) amount = height;

	int count = 1;
	char value = EMPTY;

	int cols = height - amount + 1;

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < width; j++)
		{
			count = 0;
			value = board[i][j];
			if (value == EMPTY) continue;

			for (int k = 0; k < amount; k++)
			{
				if (board[i + k][j] == value)
				{
					count++;
					if (count >= amount) return value;
				}

				else break;
			}
		}
	}

	int rows = width - amount + 1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < height; j++)
		{
			count = 0;
			value = board[j][i];

			for (int k = 0; k < amount; k++)
			{
				if (board[j][i + k] == value)
				{
					count++;
					if (count >= amount) return value;
				}

				else break;
			}
		}
	}

	if (diagonal)
	{
		// TODO: Diagonal Control
	}

	for (int i = 0; i < height; i++)

		for (int j = 0; j < width; j++)

			if (board[i][j] == EMPTY) return EMPTY;

	return VOID;
}

void Board::print()
{
	using namespace std;

	cout << endl;

	cout << "  | 1| 2| 3|";

	for (int i = 3; i < width; i++)
	{
		if (i < 9) cout << " ";
		cout << i + 1 << "|";
	}

	cout << endl;

	int dashCount = (width + 1) * 3;

	for (int d = 0; d < dashCount; d++)

		cout << "-";

	cout << endl;

	for (int i = 0; i < height; i++)
	{
		if (i < 9) cout << " ";
		cout << i + 1 << "|";

		for (int j = 0; j < width; j++)

			cout << " " << board[i][j] << "|";

		cout << endl;

		for (int d = 0; d < dashCount; d++)

			cout << "-";

		cout << endl;
	}

	cout << endl;
}

int Board::getWidth()
{
	return this->width;
}

int Board::getHeight()
{
	return this->height;
}

int Board::getAmount()
{
	return this->amount;
}

bool Board::getDiagonal()
{
	return this->diagonal;
}
