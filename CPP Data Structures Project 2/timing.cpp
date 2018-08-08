#include <iostream>
#include <ctime>
using namespace std;
#include "lcrstreeclass.h"
#include "loctreeclass.h"

void LocPreorder(locnode x){ //traverses preorder
	if (x.position_ != NULL){
		x.position_;
		for (int i = 0; i < x.LIST_.size(); i++)
			LocPreorder(x.LIST_[i]);
	}
}

void LcrsPreorder(lcrstree t, int x){ //traverses preoder
	if (t.LEFTMOST_CHILD(x) != NULL){
		t.LABEL(x);
		while (t.RIGHT_SIBLING(x)){
			LcrsPreorder(t, t.LEFTMOST_CHILD(x));
			LcrsPreorder(t, t.RIGHT_SIBLING(x));
		}
	}
}

void LocPostorder(locnode x){ //traverses postorder
	if (x.position_ != NULL){
		for (int i = 0; i < x.LIST_.size(); i++)
			LocPreorder(x.LIST_[i]);
		x.position_;
	}
}

void LcrsPostorder(lcrstree t, int x){ //traverses postorder
	if (t.LEFTMOST_CHILD(x) != NULL){
		while (t.RIGHT_SIBLING(x)){
			LcrsPreorder(t, t.LEFTMOST_CHILD(x));
			LcrsPreorder(t, t.RIGHT_SIBLING(x));
		}
		t.LABEL(x);
	}
}


int main(){
	lcrstree lcrsh2, lcrsh3, A, B, C, D, E, F, G, H, I, J, K, L, M;
	A.CREATE0("A");
	B.CREATE0("B");
	C.CREATE0("C");
	D.CREATE0("D");
	E.CREATE0("E");
	F.CREATE0("F");
	G.CREATE0("G");
	H.CREATE0("H");
	I.CREATE0("I");
	J.CREATE3("J", A, B, C);
	K.CREATE3("K", D, E, F);
	L.CREATE3("L", G, H, I);
	M.CREATE3("M", J, K, L);
	lcrsh2 = J;
	lcrsh3 = M;

	loctree loch2, loch3, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
	N.CREATE0("N");
	O.CREATE0("O");
	P.CREATE0("P");
	Q.CREATE0("Q");
	R.CREATE0("R");
	S.CREATE0("S");
	T.CREATE0("T");
	U.CREATE0("U");
	V.CREATE0("V");
	W.CREATE3("W", N, O, P);
	X.CREATE3("X", Q, R, S);
	Y.CREATE3("Y", T, U, V);
	Z.CREATE3("Z", W, X, Y);
	loch2 = W;
	loch3 = Z;

	clock_t lcrsh2Start, lcrsh2Stop, lcrsh3Start, lcrsh3Stop, loch2Start, loch2Stop, loch3Start, loch3Stop;

	//time preorder traversal for lcrs implementation
	lcrsh2Start = clock();
	LcrsPreorder(lcrsh2, lcrsh2.ROOT());
	lcrsh2Stop = clock();

	lcrsh3Start = clock();
	LcrsPreorder(lcrsh3, lcrsh3.ROOT());
	lcrsh3Stop = clock();

	//time preorder traversal for loc implementation
	loch2Start = clock();
	LocPreorder(loch2.ROOT());
	loch2Stop = clock();

	loch3Start = clock();
	LocPreorder(loch3.ROOT());
	loch3Stop = clock();

	cout << "----------Pre-order Traversal----------" << endl;
	double lcrsh2PreTimeTaken = (1000 * ((double)lcrsh2Stop - lcrsh2Start) / CLOCKS_PER_SEC);
	double loch2PreTimeTaken = (1000 * ((double)loch2Stop - loch2Start) / CLOCKS_PER_SEC);
	double lcrsh3PreTimeTaken = (1000 * ((double)lcrsh3Stop - lcrsh3Start) / CLOCKS_PER_SEC);
	double loch3PreTimeTaken = (1000 * ((double)loch3Stop - loch3Start) / CLOCKS_PER_SEC);
	cout << "Time taken to traverse the pre-order leftmost-child right-sibling tree of height 2 " << lcrsh2PreTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the pre-order lists of children tree of height 2 " << loch2PreTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the pre-order leftmost-child right-sibling tree of height 3 " << lcrsh3PreTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the pre-order lists of children tree of height 3 " << loch3PreTimeTaken << " milliseconds" << endl;

	//time postorder traversal for lcrs implementation
	lcrsh2Start = clock();
	LcrsPostorder(lcrsh2, lcrsh2.ROOT());
	lcrsh2Stop = clock();

	lcrsh3Start = clock();
	LcrsPostorder(lcrsh3, lcrsh3.ROOT());
	lcrsh3Stop = clock();

	//time postorder traversal for loc implementation
	loch2Start = clock();
	LocPostorder(loch2.ROOT());
	loch2Stop = clock();

	loch3Start = clock();
	LocPostorder(loch3.ROOT());
	loch3Stop = clock();

	cout << "----------Post-order Traversal----------" << endl;
	double lcrsh2PostTimeTaken = (1000 * ((double)lcrsh2Stop - lcrsh2Start) / CLOCKS_PER_SEC);
	double loch2PostTimeTaken = (1000 * ((double)loch2Stop - loch2Start) / CLOCKS_PER_SEC);
	double lcrsh3PostTimeTaken = (1000 * ((double)lcrsh3Stop - lcrsh3Start) / CLOCKS_PER_SEC);
	double loch3PostTimeTaken = (1000 * ((double)loch3Stop - loch3Start) / CLOCKS_PER_SEC);
	cout << "Time taken to traverse the post-order leftmost-child right-sibling tree of height 2 " << lcrsh2PostTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the post-order lists of children tree of height 2 " << loch2PostTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the post-order leftmost-child right-sibling tree of height 3 " << lcrsh3PostTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the post-order lists of children tree of height 3 " << loch3PostTimeTaken << " milliseconds" << endl;

	return 0;
}
