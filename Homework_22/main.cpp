#include"bishop.hpp"
#include"king.hpp"
#include"knight.hpp"
#include"pawn.hpp"
#include"queen.hpp"
#include"rook.hpp"
#include<iostream>
int main()
{
	bishop* first = new bishop(0);
	king* second = new king(0);
	knight* third = new knight(0);
	pawn* fourth = new pawn(0);
	queen* fifth = new queen(0);
	rook* sixth = new rook(0);
	chess_piece** ptr = new chess_piece*[6];

	ptr[0] = first;
	ptr[1] = second;
	ptr[2] = third;
	ptr[3] = fourth;
	ptr[4] = fifth;
	ptr[5] = sixth;

	int a = INT_MAX;
	std::string move;
	std::cout << "1 - bishop, 2 - king, 3 - knight, 4 - pawn, 5 - queen, 6 - rook" << std::endl;
	std::cout << "if you want to end programm write 0" << std::endl;

	while (a != 0)
	{
		std::cout << "choose your piece:";
		std::cin >> a;

		if (a > 5)
		{
			break;
		}

		std::cout << std::endl << "choose move:";
		std::cin >> move;
		ptr[a - 1]->make_move(move);
		std::cout << std::endl;
	}
}