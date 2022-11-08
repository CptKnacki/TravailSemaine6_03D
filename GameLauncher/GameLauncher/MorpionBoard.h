#pragma once
#include "Object.h"
#include <vector>

class MorpionBoard : public Object
{
#pragma region f/p
private:
	static inline const int wins[8][3] =
	{
		{0,1,2},
		{3,4,5},
		{6,7,8},
		{0,3,6},
		{1,4,7},
		{2,5,8},
		{0,4,8},
		{2,4,6}
	};
	std::vector<int> board = std::vector<int>();
#pragma endregion f/p
#pragma region constructor/destructor
public:
	MorpionBoard();
	~MorpionBoard() override;
#pragma endregion constructor/destructor
#pragma region methods
private:
	void Initialize();
public:
	static int Win(std::vector<int> _board);
	std::vector<int> GetBoard() const;
	int Win() const;
	void ShowBoard() const;
	void Reset();
	int& At(const int _index);
#pragma endregion methods
};

