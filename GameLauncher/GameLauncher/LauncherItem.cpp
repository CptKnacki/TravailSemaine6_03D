#include "LauncherItem.h"
#include "IGame.h"
#include "Utils.h"

#pragma region constructor/destructor
LauncherItem::LauncherItem(IGame* _game)
{
	game = _game;
}

LauncherItem::LauncherItem(const LauncherItem& _copy)
{
	game = _copy.game;
}

LauncherItem::~LauncherItem()
{
	delete game;
}
#pragma endregion constructor/destructor

#pragma region methods
void LauncherItem::OnClick()
{
	if (game == nullptr) throw std::exception("[Launcher Item] => current game is null !");
	Utils::ClearConsole();
	Utils::LoadingBar("Loading " + game->GameName());
	game->OnStart();
	game->DisplayMenu();
	game->OnUpdate();
	game->OnEnd();
}
void LauncherItem::Display()
{
	Utils::Log(game->GameName());
}
IGame* LauncherItem::Game() const
{
	return game;
}
#pragma endregion methods