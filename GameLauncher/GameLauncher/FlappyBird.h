#pragma once
#include "IGame.h"
#include "FlappyScore.h"

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define SLEEP_DEFAULT 100
#define GAP_SIZE 7
#define PRESS_ANY_KEY "Press any key..."

class FlappyMap;
class FlappyPlayer;
class FlappyPipe;

class FlappyBird : public IGame
{
#pragma region f/p
private:
	FlappyMap* map = nullptr;
	FlappyPlayer* player = nullptr;
	FlappyPipe* pipeOne = nullptr;
	FlappyPipe* pipeTwo = nullptr;
	FlappyScore score = FlappyScore();
	bool isQuitting = false;
	int sleepTime = 0;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FlappyBird();
	~FlappyBird() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	bool IsOutOfScreen() const;
	void Draw();
	void Clear();
	void DisplayControls();
	void UpdatePipe();
	void Init();
	void UpdateScore();
#pragma endregion methods
#pragma region override
public:
	virtual void OnStart() override;
	virtual void OnUpdate() override;
	virtual void OnEnd() override;
	virtual void DisplayMenu() override;
	virtual std::string GameName() const override;
	virtual std::string GameDescription() const override;
#pragma endregion override
};

