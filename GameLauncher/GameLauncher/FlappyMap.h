#pragma once
#include "IDrawable.h"

#define SLEEP_TIME_MAP 20

class FlappyMap : public IDrawable
{
#pragma region constructor/destructor
public:
	FlappyMap() = default;
	~FlappyMap() override = default;
#pragma endregion constructor/destructor
#pragma region override
public:
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion override
};

