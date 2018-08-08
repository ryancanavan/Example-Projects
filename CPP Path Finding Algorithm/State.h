#ifndef _State_
#define _State_

#include <vector>
#include <string>
#include "Move.h"

class State {
private:
	int width;
	int height;
	std::vector<std::vector<int>> state;
public:
	State();
	State(std::string file);
	int getWidth();
	int getHeight();
	std::vector<std::vector<int>> getState();
	void setWidth(int width);
	void setHeight(int height);
	void setState(std::vector<std::vector<int>> state);
	void printState();
	State clone();
	bool solved();
	std::vector<Move> listMoves(int piece);
	std::vector<Move> listAllMoves();
	void applyMove(Move move);
	State applyMoveClone(Move move);
	bool compare(State compState);
	void swapId(int id1, int id2);
	void normalize();
};

#endif