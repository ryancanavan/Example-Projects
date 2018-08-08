#include <iostream>
using namespace std;
#include "arraylistclass.h"

int main(){
	arraylist test;
	for (int i = 50; i > 0; i--){ // fill up list
		test.INSERT(i, test.END()); //example of INSERT
	}
	test.PRINTLIST(); //example of PRINTLIST
	cout << "The first position is " << test.FIRST() << endl; //example of FIRST
	cout << "The position one past the last filled position is " << test.END() << endl; //example of END
	cout << "The element in the 5th position is " << test.RETRIEVE(5) << endl; //example of RETRIEVE
	cout << "The element 10 is in the position " << test.LOCATE(10) << endl; //example of LOCATE
	cout << "The position after the 20th position is " << test.NEXT(20) << endl; //example of NEXT
	cout << "The position before the 20th position is " << test.PREVIOUS(20) << endl; //example of PREVIOUS
	test.DELETE(test.PREVIOUS(test.END())); //example of DELETE
	cout << "If the last element is deleted then the list is ";
	test.PRINTLIST();
	test.MAKENULL(); //example of MAKENULL
	cout << "If the list is cleared, then the list is ";
	test.PRINTLIST();

	return 0;
}
