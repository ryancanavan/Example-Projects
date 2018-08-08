#include <iostream>
#include <string>
#include "Move.h"

Move::Move(){}

Move::Move(int movePiece, int moveDirection) {
	piece = movePiece;
	direction = moveDirection;
}

void Move::printMove() {
	std::string moveDirection;
	switch(direction) {
	case 1:
		moveDirection = "up";
		break;
	case 2:
		moveDirection = "right";
		break;
	case 3:
		moveDirection = "down";
		break;
	case 4:
		moveDirection = "left";
		break;
	}
	std::cout << "(" << piece << "," << moveDirection << ")" << std::endl;
}

bool Move::isEquals(Move move) {
	if (move.piece == piece && move.direction == direction) {
		return true;
	}
	return false;
}