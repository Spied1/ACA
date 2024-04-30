#include"chess_piece.hpp"

class bishop : public chess_piece
{
public:
	bishop(bool side);

	void make_move(std::string move_to) override;
};