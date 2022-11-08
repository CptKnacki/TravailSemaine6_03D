#include <iostream>
#include "Launcher.h"
#include "LauncherItem.h"
#include "MorpionGame.h"
#include "MorpionBoard.h"
#include "FlappyBird.h"
#include <windows.h>

int main()
{
	SetConsoleTitle(L"Launcher");
	Launcher _launcher = Launcher({
		new LauncherItem(new MorpionGame()),
		new LauncherItem(new FlappyBird()),
		});
	_launcher.Open();
}