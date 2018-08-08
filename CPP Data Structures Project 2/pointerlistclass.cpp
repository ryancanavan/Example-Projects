using namespace std;
#include "pointerlistclass.h"

//initializes the list by creating an empty head
pointerlist::pointerlist(){
	head = NULL;
}

//returns the head
listnode* pointerlist::FIRST(){
	return(head);
}

//if the list is empty it returns the head otherwise it loops through the list and returns the last pointer
listnode* pointerlist::END(){
	if (head == NULL)
		return(head);
	else{
		listnode* q = head;
		while (q->next_ != NULL) //loops through list
			q = q->next_;
		return(q->next_);
	}
}

//returns the element at node p
int pointerlist::RETRIEVE(listnode* p){
	return(p->element_);
}

//returns the integer for the position x is at or returns 1 past the last position if it is not found
int pointerlist::LOCATE(int x){
	listnode* q = head;
	int pos = 1;
	while (q->next_ != NULL){ //loops through list
		if (q->element_ == x) //if element is found
			return(pos);
		else //increment pos and q
			pos++;
		q = q->next_;
	}
	return(pos + 1);
}

//returns the next node pointer
listnode* pointerlist::NEXT(listnode* p){
	return(p->next_);
}

//loops through the list and stops when it is at the node before the input p and returns that pointer
listnode* pointerlist::PREVIOUS(listnode* p){
	listnode* q = head;
	while (q->next_ != p) //loops through the list
		q = q->next_;
	return(q);
}

//If x is to be insert at the first position, the head is changed to point to the new node
//otherwise it runs through the list to the given position and inputs the node there
void pointerlist::INSERT(int x, listnode *p){
	if (p == head){
		listnode *temp = new listnode(); //creates new node to be filled with input data
		temp->next_ = head;
		temp->element_ = x;
		head = temp;
	}
	else{
		listnode *temp = new listnode();
		temp->next_ = p;
		temp->element_ = x;
		listnode* q = head;
		while (q->next_ != p) //loops through the list
			q = q->next_;
		q->next_ = temp;
	}
}

//Deletes the element directly after the input node p by making the pointers skip over the next node
void pointerlist::DELETE(listnode* p){
	if (p->next_ == NULL)
		head = NULL;
	else if (p == head)
		head = p->next_;
	else
		p->next_ = p->next_->next_;
}

//Sets the head back to NULL so the list is treated as empty and returns the new head
listnode* pointerlist::MAKENULL(){
	head = NULL;
	return(END());
}

//Starts with the head and prints out each element_ as it progresses to the next node
void pointerlist::PRINTLIST(){
	if (head == NULL){
		cout << "empty" << endl;
	}
	else{
		listnode* q = head;
		while (q != NULL){ //loops through the list and prints out each element
			cout << q->element_ << " ";
			q = q->next_;
		}
		cout << endl;
	}
}