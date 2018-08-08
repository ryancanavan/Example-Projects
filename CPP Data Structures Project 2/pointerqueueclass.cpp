using namespace std;
#include "pointerqueueclass.h"

//initializes by creating NULL front and rear
pointerqueue::pointerqueue(){
	front = NULL;
	rear = front;
}

//returns the element of front
int pointerqueue::FRONT(){
	queuenode* q = front;
	return(q->element_);
}

//adds integer x to the rear of the queue
void pointerqueue::ENQUEUE(int x){
	queuenode *temp = new queuenode(); //creates new node to add to queue
	temp->element_ = x; //adds data to the new node
	temp->next_ = NULL; //node is at end of list so NULL next value
	if (front == NULL)
		front = temp; //if it is first element then have front point to it
	else
		rear->next_ = temp; //if it is not the first element, add it to the end
	rear = temp; //make rear point to new rear
}

//removes first element by having front point to second node
void pointerqueue::DEQUEUE(){
	front = front->next_;
}

//checks if front is NULL and therefore if queue is empty
bool pointerqueue::EMPTY(){
	if (front == NULL)
		return(true);
	else
		return(false);
}

//sets front to NULL to make queue appear empty
void pointerqueue::MAKENULL(){
	front = NULL;
}

//prints out all elements of queue in order
void pointerqueue::PRINT(){
	if (front == NULL)
		cout << "empty" << endl;
	else{
		queuenode* q = front;
		while (q != NULL){ //loops through all elements of queue and prints thems
			cout << q->element_ << " ";
			q = q->next_;
		}
		cout << endl;
	}
}