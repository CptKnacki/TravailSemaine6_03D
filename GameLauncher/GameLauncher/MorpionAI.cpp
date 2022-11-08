#include "MorpionAI.h"
#include "MorpionBoard.h"

int MorpionAI::MinMax(std::vector<int> _board, int _player)
{
	const int _winner = MorpionBoard::Win(_board);
	if (_winner != 0) return _winner * _player;

	int _move = -1, _score = -2;

	for (int i = 0; i < 9; i++)
	{
		if (_board[i] == 0)
		{
			_board[i] = _player;
			const int _tempScore = -MinMax(_board, _player * -1);
			if (_tempScore > _score)
			{
				_score = _tempScore;
				_move = i;
			}
			_board[i] = 0;
		}
	}

	return _move == -1 ? 0 : _score;
}

int MorpionAI::BestMove(MorpionBoard _board)
{
	int _move = -1;
	int _score = -2;

	for (int i = 0; i < 9; i++)
	{
		if (_board.At(i) == 0)
		{
			_board.At(i) = 1;
			const int _tempScore = -MinMax(_board.GetBoard(), -1);
			_board.At(i) = 0;
			if (_tempScore > _score)
			{
				_score = _tempScore;
				_move = i;
			}
		}
	}

	return _move;
}
