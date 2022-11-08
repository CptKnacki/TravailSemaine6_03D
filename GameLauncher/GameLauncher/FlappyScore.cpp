#include "FlappyScore.h"
#include "FlappyBird.h"
#include "Utils.h"

#pragma region override
void FlappyScore::Draw()
{
	Utils::SetCursorPosition(WIN_WIDTH + 7, 5);
	std::cout << "Score: " << score;
}

void FlappyScore::Erase()
{
}

void FlappyScore::Update()
{
	score++;
}
#pragma endregion override
#pragma region operator
FlappyScore::operator int() const
{
	return score;
}

FlappyScore& FlappyScore::operator=(const int _value)
{
	score = _value;
	return *this;
}

FlappyScore& FlappyScore::operator+=(const int _value)
{
	score += _value;
	return *this;
}
#pragma endregion operator