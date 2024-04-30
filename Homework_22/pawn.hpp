#include"chess_piece.hpp"

class pawn : public chess_piece
{
public:
	pawn(bool side);

	void make_move(std::string move_to) override;
}; 