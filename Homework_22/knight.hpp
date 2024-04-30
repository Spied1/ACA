#include"chess_piece.hpp"

class knight : public chess_piece
{
public:
	knight(bool side);

	void make_move(std::string move_to) override;
};