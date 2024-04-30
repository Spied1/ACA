#include"chess_piece.hpp"

class rook : public chess_piece
{
public:
	rook(bool side);

	void make_move(std::string move_to) override;
};