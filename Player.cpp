#include "Player.h"
#include "Board.h"

using namespace tictactoe;
using namespace std;

Player::Player(string name, char character)
{
	this->name = name;
	this->character = character;
}

Player::Player()
{
	this->name = "NO_NAME";
	this->character = EMPTY;
}

string Player::getName()
{
	return this->name;
}

char Player::getCharacter()
{
	return this->character;
}
