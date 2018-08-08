#ifndef _Move_
#define _Move_

// direction: 1=up, 2=right, 3=down, 4=left
class Move {
public:	
	int piece;
	int direction;
	Move();
	Move(int piece, int direction);
	void printMove();
	bool isEquals(Move move);
};

#endif