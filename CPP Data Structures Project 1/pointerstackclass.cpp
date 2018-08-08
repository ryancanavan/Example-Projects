using namespace std;
#include "pointerstackclass.h"

//initializes stack by creating empty head
pointerstack::pointerstack(){
	head = NULL;
}

//returns the top element of the stack
int pointerstack::TOP(){
	stacknode* q = head;
	return(q->element_); //element in head
}

//returns the top element and removes it
int pointerstack::POP(){
	int result = TOP();
	head = head->next_;
	return(result);
}

//adds new node to top of stack
void pointerstack::PUSH(int x){
	stacknode *temp = new stacknode(); //creates new node to be filled with input data
	temp->next_ = head;
	temp->element_ = x;
	head = temp;
}

//checks if stack is empty
bool pointerstack::EMPTY(){
	if (head == NULL)
		return(true);
	else
		return(false);
}

//sets head to null so stack is treated as empty
stacknode* pointerstack::MAKENULL(){
	head = NULL;
	return(head);
}

//prints out the stack
void pointerstack::PRINTLIST(){
	if (head == NULL)
		cout << "empty" << endl;
	else{
		stacknode* q = head;
		while (q != NULL){ //runs through stack
			cout << q->element_ << " ";
			q = q->next_;
		}
		cout << endl;
	}
}