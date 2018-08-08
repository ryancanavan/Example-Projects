#ifndef _POINTER_QUEUE_
#define _POINTER_QUEUE_

#include <iostream>
using namespace std;

struct queuenode{ //node
	int element_; //data
	queuenode *next_; //pointer to next node
};

class pointerqueue
{
private:
	queuenode *front; //pointer to first element
	queuenode *rear; //pointer to last element
public:
	pointerqueue(); //constructor
	int FRONT(); //returns first element in queue
	void ENQUEUE(int x); //adds element to end of queue
	void DEQUEUE(); //deletes first element in queue
	bool EMPTY(); //checks if queue is empty
	void MAKENULL(); //empties queue
	void PRINT(); //prints out queue
};

#endif