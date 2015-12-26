#pragma once
#define EMPTY '.'
#define VOID '#'
#define MIN 3
#define MAX 15

namespace tictactoe
{
	class Board
	{
	private:
		char board[MAX][MAX];
		int width;
		int height;
		int amount;
		bool diagonal;

	public:
		Board(int width, int height, int amount, bool diagonal);
		Board();
		char get(int x, int y);
		void set(int x, int y, char c);
		char winner();
		void print();
		int getWidth();
		int getHeight();
		int getAmount();
		bool getDiagonal();
	};
}
