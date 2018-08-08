#include <iostream>
using namespace std;
#include "pointerqueueclass.h"

int main(){
	pointerqueue test;
	for (int i = 50; i > 0; i--){ // fill up queue
		test.ENQUEUE(i); //example of ENQUEUE
	}
	test.PRINT(); //example of PRINT
	cout << "The element in the front of the queue is " << test.FRONT() << endl; //example of FRONT
	test.DEQUEUE(); //example of DEQUEUE
	cout << "If the first element of the queue is removed the queue is now ";
	test.PRINT();
	cout << "The queue is not empty so the EMPTY function returns " << test.EMPTY() << endl; //example of EMPTY
	test.MAKENULL(); //example of MAKENULL
	cout << "Once the queue is emptied, the EMPTY function returns " << test.EMPTY() << " and now the queue is ";
	test.PRINT();

	return 0;
}
