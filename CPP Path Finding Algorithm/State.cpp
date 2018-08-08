#include <sstream>
#include <fstream>
#include <iostream>
#include "State.h"

//empty constructor
State::State() {}

//constructor takes in file and creates State
State::State(std::string file) {
	std::vector<int> row;
	std::string line;
	std::ifstream source(file);

	std::getline(source, line);
	width = std::stoi(line.substr(0, 1));
	height = std::stoi(line.substr(2, 1));
	while (std::getline(source, line))
	{
		std::stringstream ss(line);
		int i;
		while (ss >> i) {
			row.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}
		state.push_back(row);
		row.clear();
	}
	source.close();
}

int State::getWidth() {
	return width;
}

int State::getHeight() {
	return height;
}

std::vector<std::vector<int>> State::getState() {
	return state;
}

void State::setWidth(int setWidth) {
	width = setWidth;
}

void State::setHeight(int setHeight) {
	height = setHeight;
}

void State::setState(std::vector<std::vector<int>> setState) {
	state = setState;
}

//print State to console
void State::printState() {
	std::cout << width << "," << height << "," << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << state[i][j] << ",";
		}
		std::cout << std::endl;
	}
}

//clone State and return clone
State State::clone() {
	State temp;
	temp.setWidth(width);
	temp.setHeight(height);
	temp.setState(state);
	return temp;
}

//true if puzzle is solved and false if not
bool State::solved() {
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++){
			if (state[i][j] == -1)
				return false;
		}
	}
	return true;
}

//return vector of all possible moves for input piece
std::vector<Move> State::listMoves(int piece) {
	std::vector<Move> moves = {Move(piece, 1), Move(piece, 2), Move(piece, 3), Move(piece, 4)};
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			if (state[i][j] == piece) {
				//check up
				if (!(state[i - 1][j] == 0 || state[i - 1][j] == piece) || (piece == 2 && state[i - 1][j] == -1)) {
					for (int k = 0; k < moves.size(); k++) {
						if (moves[k].isEquals(Move(piece, 1))) {
							moves.erase(moves.begin() + k);
						}
					}
				}
				//check right
				if (!(state[i][j + 1] == 0 || state[i][j + 1] == piece) || (piece == 2 && state[i][j + 1] == -1)) {
					for (int k = 0; k < moves.size(); k++) {
						if (moves[k].isEquals(Move(piece, 2))) {
							moves.erase(moves.begin() + k);
						}
					}
				}
				//check down
				if (!(state[i + 1][j] == 0 || state[i + 1][j] == piece) || (piece == 2 && state[i + 1][j] == -1)) {
					for (int k = 0; k < moves.size(); k++) {
						if (moves[k].isEquals(Move(piece, 3))) {
							moves.erase(moves.begin() + k);
						}
					}
				}
				//check left
				if (!(state[i][j - 1] == 0 || state[i][j - 1] == piece) || (piece == 2 && state[i][j - 1] == -1)) {
					for (int k = 0; k < moves.size(); k++) {
						if (moves[k].isEquals(Move(piece, 4))) {
							moves.erase(moves.begin() + k);
						}
					}
				}
			}
		}
	}
	return moves;
}

//true if moves parameter contains a move for the given piece otherwise false
bool containsPiece(std::vector<Move> moves, int piece) {
	for (int i = 0; i < moves.size(); i++) {
		if (moves[i].piece == piece) {
			return true;
		}
	}
	return false;
}

//return list of all possible moves at given state
std::vector<Move> State::listAllMoves() {
	std::vector<Move> moves, temp;
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			if (state[i][j] >= 2) {
				if (!containsPiece(moves, state[i][j])) {
					temp = listMoves(state[i][j]);
					for (int k = 0; k < temp.size(); k++) {
						moves.push_back(temp[k]);
					}
				}
			}
		}
	}
	return moves;
}

//edits state with the given move
void State::applyMove(Move move) {
	//move up or left
	if (move.direction == 1 || move.direction == 4) {
		for (int i = 0; i < state.size(); i++) {
			for (int j = 0; j < state[i].size(); j++) {
				if (state[i][j] == move.piece) {
					if (move.direction == 1) {
						state[i - 1][j] = move.piece;
						state[i][j] = 0;
					}
					else {
						state[i][j - 1] = move.piece;
						state[i][j] = 0;
					}
				}
			}
		}
	}
	else {
		for (int i = state.size() - 1; i >= 0; i--) {
			for (int j = state[i].size() - 1; j >= 0; j--) {
				if (state[i][j] == move.piece) {
					if (move.direction == 3) {
						state[i + 1][j] = move.piece;
						state[i][j] = 0;
					}
					else {
						state[i][j + 1] = move.piece;
						state[i][j] = 0;
					}
				}
			}
		}
	}

}

//creates a new copy state and the applies the given move
State State::applyMoveClone(Move move) {
	State temp = this->clone();
	temp.applyMove(move);
	return temp;
}

//true if parameter State is same as current State
bool State::compare(State compState) {
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			if (state[i][j] != compState.getState()[i][j])
				return false;
		}
	}
	return true;
}

void State::swapId(int id1, int id2) {
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			if (state[i][j] == id1) {
				state[i][j] = id2;
			}
			else if (state[i][j] == id2) {
				state[i][j] = id1;
			}
		}
	}
}

//normalize the state by putting all of the pieces in order from top left to bottom right
void State::normalize() {
	int nextId = 3;
	for (int i = 0; i < state.size(); i++) {
		for (int j = 0; j < state[i].size(); j++) {
			if (state[i][j] == nextId) {
				nextId++;
			}
			else if (state[i][j] > nextId) {
				swapId(nextId, state[i][j]);
				nextId++;
			}
		}
	}
}