#pragma once
#include "Object.h"

class IDrawable : public Object
{
#pragma region destructor
public:
	~IDrawable() override = default;
#pragma endregion destructor
#pragma region methods
public:
	virtual void Draw() = 0;
	virtual void Erase() = 0;
	virtual void Update() = 0;
#pragma endregion methods
};