using namespace std;
#include "arraystackclass.h"

const int arraystack::maxLength;

//constructor sets top_ to the maxLength
arraystack::arraystack(){
	top_ = maxLength;
}

//returns the top element of the stack so the most recent element added
int arraystack::TOP(){
	if (EMPTY()) //if stack is empty
		return(-1);
	else
		return(elements_[top_]);
}

//returns the top element of the stack and removes it from the stack
int arraystack::POP(){
	if (EMPTY()) //if stack is empty
		return(-1);
	else{
		int result = TOP();
		top_++; //set top to new pos
		return(result);
	}
}
 
//adds a new element to the top of the stack
void arraystack::PUSH(int x){
	if (top_ == 1) //if stack is full
		cout << "stack is full" << endl;
	else{
		top_--;
		elements_[top_] = x;
	}
}

//checks if the stack is empty or not
bool arraystack::EMPTY(){
	if (top_ >= maxLength)
		return(true);
	else
		return(false);
}

//sets top_ back to maxLength so it treats the stack as empty again
int arraystack::MAKENULL(){
	top_ = maxLength;
	return(top_ + 1);
}

//prints out the stack
void arraystack::PRINTLIST(){
	if (top_ == maxLength)
		cout << "empty" << endl;
	else{
		for (int i = top_; i < (maxLength - 1); i++) //loops through stack
			cout << elements_[i] << ", ";
		cout << elements_[maxLength - 1] << endl;
	}
}