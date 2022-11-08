#pragma once
#include "Object.h"
#include <vector>

class MorpionBoard;

class MorpionAI : public Object
{
#pragma region constructor/destructor
public:
	MorpionAI() = default;
	~MorpionAI() = default;
#pragma endregion constructor/destructor
#pragma region methods
private:
	int MinMax(std::vector<int> _board, int _player);
public:
	int BestMove(MorpionBoard _board);
#pragma endregion methods
};

