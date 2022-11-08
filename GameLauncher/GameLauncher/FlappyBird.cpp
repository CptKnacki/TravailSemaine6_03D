#include "FlappyBird.h"
#include "Utils.h"
#include "FlappyMap.h"
#include "FlappyPlayer.h"
#include "FlappyPipe.h"

#pragma region constructor/destructor
FlappyBird::FlappyBird()
{
    map = new FlappyMap();
    player = new FlappyPlayer();
    pipeOne = new FlappyPipe();
    pipeTwo = new FlappyPipe();
}
FlappyBird::~FlappyBird()
{
    delete map;
    map = nullptr;
    delete player;
    player = nullptr;
    delete pipeOne;
    pipeOne = nullptr;
    delete pipeTwo;
    pipeTwo = nullptr;
}
#pragma endregion constructor/destructor

#pragma region methods
bool FlappyBird::IsOutOfScreen() const
{
    const int _position = player->Position();
    return _position > SCREEN_HEIGHT - 2 || _position <= 3;
}
void FlappyBird::Draw()
{
    player->Draw();
    pipeOne->Draw();
    pipeTwo->Draw();
}

void FlappyBird::Clear()
{
    player->Erase();
    pipeOne->Erase();
    pipeTwo->Erase();
}

void FlappyBird::DisplayControls()
{
    Utils::SetCursorPosition(WIN_WIDTH + 5, 2);
    Utils::LogWithEffect(GameName());
    Utils::SetCursorPosition(WIN_WIDTH + 6, 4);
    Utils::LogWithEffect("----------");
    Utils::SetCursorPosition(WIN_WIDTH + 6, 6);
    Utils::LogWithEffect("----------");
    Utils::SetCursorPosition(WIN_WIDTH + 7, 12);
    Utils::LogWithEffect("Control ");
    Utils::SetCursorPosition(WIN_WIDTH + 7, 13);
    Utils::LogWithEffect("-------- ");
    Utils::SetCursorPosition(WIN_WIDTH + 2, 14);
    Utils::LogWithEffect("Spacebar for jump");
}
void FlappyBird::UpdatePipe()
{
    pipeOne->Update();
    pipeTwo->Update();

    const int _pipePosition = pipeOne->Position();
    if (_pipePosition >= 40 && _pipePosition < 42)
    {
        pipeTwo->SetCanDraw(true);
        pipeTwo->SetPosition(4);
        pipeTwo->SetGapPosition(Utils::Random(3,14)); // TODO change random
    }
}
void FlappyBird::Init()
{
    isQuitting = false;
    score = 0;
    player->SetDead(false);
    player->SetPosition(6);
    pipeOne->SetCanDraw(true);
    pipeTwo->SetCanDraw(false);
    pipeOne->SetPosition(4);
    pipeTwo->SetPosition(4);
    pipeOne->SetGapPosition(Utils::Random(3, 14));

}
void FlappyBird::UpdateScore()
{
    if (pipeOne->Position() > 68)
    {
        //TODO score upate
        score.Update();
        score.Draw();
        pipeTwo->SetCanDraw(false);
        pipeOne->SetPosition(pipeTwo->Position());
        pipeOne->SetGapPosition(pipeTwo->GapPosition());
    }
}
#pragma endregion methods

#pragma region override

void FlappyBird::OnStart()
{
    Utils::SetWindowSize(SCREEN_WIDTH * 10, SCREEN_HEIGHT * 20);
    Utils::ClearConsole();
    Utils::SetCursor(false, 0);
    sleepTime = SLEEP_DEFAULT;
    Init();
    map->Draw();
}

void FlappyBird::OnUpdate()
{
    while (!player->IsDead() && !isQuitting)
    {
        const char _input = Utils::CinNoBlock();
        if (_input == SPACE) player->Jump();
        else if (_input == ESCAPE)
        {
            isQuitting = true;
            continue;
        }
        Draw();

        if (player->IsCollide(pipeOne))
        {
            player->SetDead(true);
            continue;
        }

        Utils::Sleep(sleepTime);
        Clear();
        player->Update();

        if (IsOutOfScreen())
        {
            player->SetDead(true);
            continue;
        }

        UpdatePipe();
        UpdateScore();
    }
}

void FlappyBird::OnEnd()
{
    player->Draw();
    Utils::SetCursorPosition(15, 5);
    std::cout << "SCORE: " << score;
    Utils::SetCursorPosition(15, 6);
    std::cout << PRESS_ANY_KEY;
    _getch();
    Utils::SetCursor(true, 20);

}

void FlappyBird::DisplayMenu()
{
    DisplayControls();
    score.Draw();
    Utils::SetCursorPosition(10, 5);
    std::cout << PRESS_ANY_KEY;
    _getch(); // _ => if not pragma warning
    Utils::SetCursorPosition(10, 5);
    std::cout << Utils::Separator(strlen(PRESS_ANY_KEY), ' ');
}

std::string FlappyBird::GameName() const
{
    return "Flappy Bird";
}

std::string FlappyBird::GameDescription() const
{
    return "Flappy Bird Game !";
}
#pragma endregion override