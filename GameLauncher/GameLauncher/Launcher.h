#pragma once
#include "Object.h"
#include <vector>

class IGame;
class LauncherItem;

class Launcher : public Object
{
#pragma region f/p
private:
	bool isOpen = true;
	int currentGameIndex = -1;
	IGame* currentGame = nullptr;
	std::vector<LauncherItem*> items = std::vector<LauncherItem*>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Launcher() = default;
	Launcher(const std::initializer_list<LauncherItem*> _items);
	~Launcher() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Update();
	void StartGame();
	void DisplayItems();
public:
	void Open();
#pragma endregion methods
};

