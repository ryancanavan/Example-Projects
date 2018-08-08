#include <iostream>
using namespace std;
#include "pointerlistclass.h"

int main(){
	pointerlist test;
	for (int i = 50; i > 0; i--){ // fill up list
		test.INSERT(i, test.FIRST()); //example of INSERT
	}
	test.PRINTLIST(); //example of PRINTLIST
	cout << "The element in the first position is " << test.RETRIEVE(test.FIRST()) << endl; //example of FIRST
	cout << "The element in the last position is " << test.RETRIEVE(test.PREVIOUS(test.END())) << endl; //example of END
	cout << "The element in the 2nd position is " << test.RETRIEVE(test.NEXT(test.FIRST())) << endl; //example of RETRIEVE
	cout << "The element 10 is in the position " << test.LOCATE(10) << endl; //example of LOCATE
	cout << "The element after the 2nd position is " << test.RETRIEVE(test.NEXT(test.NEXT(test.FIRST()))) << endl; //example of NEXT
	cout << "The element before the 2nd position is " << test.RETRIEVE(test.PREVIOUS(test.NEXT(test.FIRST()))) << endl; //example of PREVIOUS
	test.DELETE(test.FIRST()); //example of DELETE
	cout << "If the second element is deleted then the list is ";
	test.PRINTLIST();
	test.MAKENULL(); //example of MAKENULL
	cout << "If the list is cleared, then the list is ";
	test.PRINTLIST();
	

	return 0;
}
