#pragma once
#include "IDrawable.h"

#define PIPE "***"

class FlappyPipe : public IDrawable
{
#pragma region f/p
private:
	int gapPosition = 0;
	int position = 0;
	bool canDraw = false;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	FlappyPipe() = default;
	~FlappyPipe() override = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	void SetGapPosition(const int _gap);
	void SetPosition(const int _position);
	void SetCanDraw(const bool _status);
	int GapPosition() const;
	int Position() const;
	bool CanDraw() const;
#pragma endregion methods
#pragma region override
public:
	virtual void Draw() override;
	virtual void Erase() override;
	virtual void Update() override;
#pragma endregion override
};

