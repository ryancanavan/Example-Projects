#include <iostream>
using namespace std;
#include "loctreeclass.h"

int main(){
	loctree test, A, B, C, D, E, F, G, H, I, J;

	D = D.CREATE0("D"); //example of CREATE0
	F = F.CREATE0("F");
	G = G.CREATE0("G");
	H = H.CREATE0("H");
	I = I.CREATE0("I");
	J = J.CREATE0("J");

	E = E.CREATE3("E", H, I, J); //example of CREATE3
	B = B.CREATE2("B", D, E); //example of CREATE 2
	C = C.CREATE2("C", F, G);
	A = A.CREATE2("A", B, C);

	test = A;

	test.PRINT(); //example of print

	cout << "The element at the root of the tree is " << test.LABEL(test.ROOT()) << endl; //example of ROOT and LABEL
	cout << "The leftmost child of the root is " << test.LABEL(test.LEFTMOST_CHILD(test.ROOT())) << endl; //example of LEFTMOST_CHILD
	cout << "The parent of that node is " << test.LABEL(test.PARENT(test.LEFTMOST_CHILD(test.ROOT()))) << endl; //example of PARENT
	test.MAKENULL(); //example of MAKENULL
	cout << "Once the tree is emptied the tree is ";
	test.PRINT();

	return 0;
}
