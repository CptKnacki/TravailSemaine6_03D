#include "FlappyMap.h"
#include "FlappyBird.h"
#include "Utils.h"

void FlappyMap::Draw()
{
	for (int i = 0; i < SCREEN_WIDTH + 1; i++)
	{
		Utils::SetCursorPosition(i, 0);
		std::cout << "±";
		Utils::SetCursorPosition(i, SCREEN_HEIGHT);
		std::cout << "±";
		Utils::Sleep(SLEEP_TIME_MAP);
	}

	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(0, i);
		std::cout << "±";
		Utils::SetCursorPosition(SCREEN_WIDTH, i);
		std::cout << "±";
		Utils::Sleep(SLEEP_TIME_MAP);
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		Utils::SetCursorPosition(WIN_WIDTH, i);
		std::cout << "±";
		Utils::Sleep(SLEEP_TIME_MAP);
	}
}

void FlappyMap::Erase()
{
}

void FlappyMap::Update()
{
}
