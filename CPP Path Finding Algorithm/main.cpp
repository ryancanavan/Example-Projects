#include <time.h>
#include "State.h"
#include "Move.h"

void randomWalk(State state, int N) {
	int rand;
	std::vector<Move> moves;
	Move move;

	srand(time(NULL));

	state.printState();

	for (int i = 0; i < N; i++) {
		moves = state.listAllMoves();
		rand = std::rand() % moves.size();
		move = moves[rand];
		move.printMove();
		state.applyMove(move);
		state.normalize();
		state.printState();
		if (state.solved())
			return;
	}
}

int main(int argc, char * argv[]) {
	State state(argv[1]);

	randomWalk(state, std::stoi(argv[2]));

	return 0;
}