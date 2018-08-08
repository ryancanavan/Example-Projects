#include <iostream>
using namespace std;
#include "pointerstackclass.h"

int main(){
	pointerstack test;
	for (int i = 50; i > 0; i--){ // fill up list
		test.PUSH(i); //example of PUSH
	}
	test.PRINTLIST(); //example of PRINTLIST
	cout << "The top element of the stack is " << test.TOP() << endl; //example of TOP
	cout << "If the top element is popped from the stack, the element is " << test.POP() << " and now the list is "; //example of POP
	test.PRINTLIST();
	cout << "The list is not empty so the EMPTY function returns " << test.EMPTY() << endl; //example of EMPTY
	test.MAKENULL(); //example of MAKENULL
	cout << "Once the list is emptied, the EMPTY function returns " << test.EMPTY() << " and now the list is ";
	test.PRINTLIST();

	return 0;
}
