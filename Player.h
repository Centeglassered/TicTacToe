#pragma once
#include <string>

namespace tictactoe
{
	class Player
	{
	private:
		std::string name;
		char character;

	public:
		Player(std::string name, char character);
		Player();
		std::string getName();
		char getCharacter();
	};
}

