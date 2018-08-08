#include <iostream>
using namespace std;
#include "lcrstreeclass.h"

int main(){
	lcrstree test, A, B, C, D, E, F, G, H, I, J;

	D.CREATE0("D"); //example of CREATE0
	F.CREATE0("F");
	G.CREATE0("G");
	H.CREATE0("H");
	I.CREATE0("I");
	J.CREATE0("J");

	E.CREATE3("E", H, I, J); //example of CREATE3
	B.CREATE2("B", D, E); //example of CREATE 2
	C.CREATE2("C", F, G);
	A.CREATE2("A", B, C);

	test = A;

	test.PRINT(); //example of print

	cout << "The element at the root of the tree is " << test.LABEL(test.ROOT()) << endl; //example of ROOT and LABEL
	cout << "The leftmost child of the root is " << test.LABEL(test.LEFTMOST_CHILD(test.ROOT())) << endl; //example of LEFTMOST_CHILD
	cout << "The right sibling of the leftmost child of the root is " << test.LABEL(test.LEFTMOST_CHILD(test.RIGHT_SIBLING(test.ROOT()))) << endl; //example of RIGHT_SIBLING
	cout << "The parent of that node is " << test.LABEL(test.PARENT(test.LEFTMOST_CHILD(test.RIGHT_SIBLING(test.ROOT())))) << endl; //example of PARENT
	test.MAKENULL(); //example of MAKENULL
	cout << "Once the tree is emptied the tree is ";
	test.PRINT();

	return 0;
}
