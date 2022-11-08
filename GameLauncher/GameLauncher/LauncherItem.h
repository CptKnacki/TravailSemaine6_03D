#pragma once
#include "Object.h"

class IGame;

class LauncherItem : public Object
{
#pragma region f/p
private:
	IGame* game = nullptr;
#pragma endregion f/p

#pragma region constructor/destructor
public:
	LauncherItem() = default;
	LauncherItem(IGame* _game);
	LauncherItem(const LauncherItem& _copy);
	~LauncherItem() override;
#pragma endregion constructor/destructor

#pragma region methods
public:
	void OnClick();
	void Display();
	IGame* Game() const;
#pragma endregion methods
};

