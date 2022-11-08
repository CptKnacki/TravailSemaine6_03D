#include "MorpionGame.h"
#include "MorpionBoard.h"
#include "MorpionAI.h"
#include "Utils.h"
#include <format>

#pragma region constructor/destructor
MorpionGame::MorpionGame()
{
	board = new MorpionBoard();
}
MorpionGame::~MorpionGame()
{
	delete board;
	delete ai;
}
#pragma endregion constructor/destructor

#pragma region methods

void MorpionGame::OnStart()
{
	winner = 0;
}

void MorpionGame::OnUpdate()
{
	int _moves = 0;
	while (winner == 0 && _moves < 9)
	{
		Utils::ClearConsole();
		board->ShowBoard();
		const bool _isPlayerTwo = currentPlayer % 2 == 0;
		if (_isPlayerTwo && ai != nullptr)
		{
			int _currentMove = ai->BestMove(*board);
			board->At(_currentMove) = 1;
			_moves++;
		}
		else
		{
			PlayerTurn(_isPlayerTwo, _moves);
		}
		currentPlayer++;
		winner = board->Win();
	}
}

void MorpionGame::PlayerTurn(const bool& _isPlayerTwo, int& _moves)
{
	Utils::Log(std::format("Player {}: turn: ", _isPlayerTwo ? 2 : 1));
	int _currentMove = Utils::UserChoice<int>();
	if (_currentMove <= 0 || _currentMove > 9)
		throw std::exception("[Morpion Game] => move out of range !");
	if (board->At(_currentMove - 1) == 0)
	{
		board->At(_currentMove - 1) = _isPlayerTwo ? 1 : -1;
		_moves++;
	}
}

void MorpionGame::OnEnd()
{
	Utils::ClearConsole();
	board->ShowBoard();
	board->Reset();
	if (winner == 0)
		Utils::Log("Equality");
	else
	{
		const std::string& _winnerName = winner == 1 ? ai != nullptr ? "AI" : "Player 2" : "Player 1";
		Utils::Log(std::format("Winner is: {}", _winnerName));
	}
	Utils::Pause();
}

void MorpionGame::DisplayMenu()
{
	Utils::ClearConsole();
	Utils::LogTitle(GameName());
	const std::string _msg = "1- Player vs Player\n2- Player vs AI\n";
	char _choice = Utils::UserChoice<char>(_msg, '0', '1', '2');
	if (_choice == '2')
		ai = new MorpionAI();
	else
	{
		delete ai;
		ai = nullptr;
	}

	_choice = Utils::UserChoice<char>("Do you want to start first ? (y/n): ", '-1', 'y', 'n');
	currentPlayer = _choice == 'y' ? 1 : 2;

}

std::string MorpionGame::GameName() const
{
	return "Morpion";
}

std::string MorpionGame::GameDescription() const
{
	return "Morpion game, you can play with another player or with a AI";
}
#pragma endregion methods