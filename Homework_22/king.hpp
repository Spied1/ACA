#include"chess_piece.hpp"

class king : public chess_piece
{
public:
	king(bool side);

	void make_move(std::string move_to) override;
};