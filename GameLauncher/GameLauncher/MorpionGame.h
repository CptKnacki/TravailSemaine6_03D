#pragma once
#include "IGame.h"

class MorpionBoard;
class MorpionAI;

class MorpionGame : public IGame
{
#pragma region f/p
private:
	MorpionBoard* board = nullptr;
	MorpionAI* ai = nullptr;
	int winner = 0;
	int currentPlayer = 1;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	MorpionGame();
	~MorpionGame() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void PlayerTurn(const bool& _isPlayerTwo, int& _moves);
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
#pragma endregion methods
};

