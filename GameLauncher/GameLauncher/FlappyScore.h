#pragma once
#include "IDrawable.h"
class FlappyScore : public IDrawable
{
#pragma region f/p
private:
	int score = 0;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FlappyScore() = default;
	~FlappyScore() override = default;
#pragma endregion constructor/destructor
#pragma region override
public:
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion override
#pragma region operator
	operator int() const;
	FlappyScore& operator=(const int _value);
	FlappyScore& operator+=(const int _value);
#pragma endregion operator
};

