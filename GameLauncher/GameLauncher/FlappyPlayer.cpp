#include "FlappyPlayer.h"
#include "Utils.h"
#include "FlappyPipe.h"
#include "FlappyBird.h"

#pragma region methods
int FlappyPlayer::Position() const
{
    return position;
}

bool FlappyPlayer::IsDead() const
{
    return isDead;
}

void FlappyPlayer::SetPosition(const int _position)
{
    position = _position;
}

void FlappyPlayer::SetDead(const bool _status)
{
    isDead = _status;
    bird[0][3] = isDead ? 'x' : 'o';
}

void FlappyPlayer::Jump()
{
    if (position > 3)
        position -= 3;
}
bool FlappyPlayer::IsCollide(const FlappyPipe* _pipe)
{
    if (_pipe->Position() >= 61)
    {
        if (position < _pipe->GapPosition() || position > _pipe->GapPosition() + GAP_SIZE)
            return true;
    }
    return false;
}
#pragma endregion methods

#pragma region override
void FlappyPlayer::Draw()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            Utils::SetCursorPosition(j + 2, i + position);
            std::cout << bird[i][j];
        }
    }
}

void FlappyPlayer::Erase()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            Utils::SetCursorPosition(j + 2, i + position);
            std::cout << " ";
        }
    }
}

void FlappyPlayer::Update()
{
    position += 1;
}
#pragma endregion override