using namespace std;
#include "arraylistclass.h"

const int arraylist::maxLength;

//constructor sets last_ to -1 because list is empty
arraylist::arraylist(){
	last_ = -1;
}

//returns first position or END() if list is empty
int arraylist::FIRST(){
	if (last_ == -1)
		return(END()); //if list is empty
	else
		return(0);
}

//returns the position one past the last position
int arraylist::END(){
	return(last_ + 1);
}

//returns the element at the input position
int arraylist::RETRIEVE(int p){
	if (p < 0 || p > last_)
		return(-1); //if p is not in list
	else
		return(elements_[p]);
}

//returns the position of the first instance of the input element or 
//END() if the element is not found
int arraylist::LOCATE(int x){
	for (int i = 0; i <= last_; i++){ //loops through list
		if (elements_[i] == x)
			return i;
	}
	return(END()); //if x is not found
}

//returns the next position from the input
int arraylist::NEXT(int p){
	if (p < 0 || p > last_)
		return(-1); //if p is not in list
	else
		return(p + 1);
}

//returns the previous position from the input
int arraylist::PREVIOUS(int p){
	if (p < 1 || p > END())
		return(-1); //if p is not in list
	else
		return(p - 1);
}

//inserts the input element into the input position if the position
//exists and the list is not full
void arraylist::INSERT(int x, int p){
	if (last_ >= (maxLength - 1)) //if list if full
		cout << "list is full" << endl;
	else if (p > END() || p < 0) //if p is not in list
		cout << "position does not exist" << endl;
	else{
		for (int i = last_; i >= p; i--) //loops through list
			elements_[i + 1] = elements_[i];
		last_++; //set last to new pos
		elements_[p] = x;
	}
}

//deletes the element at the input position
void arraylist::DELETE(int p){
	if (p < 0 || p > last_) //if p is not in list
		cout << "position does not exist" << endl;
	else{
		last_--;
		for (int i = p; i <= last_; i++) //loops through list
			elements_[i] = elements_[i + 1];
	}
}

//sets last_ to -1 so the list is treated as empty
int arraylist::MAKENULL(){
	last_ = -1;
	return(END());
}

//prints out the list
void arraylist::PRINTLIST(){
	if (last_ == -1)
		cout << "empty" << endl;
	else{
		for (int i = 0; i < last_; i++){ //loops through list
			cout << elements_[i];
			cout << ", ";
		}
		cout << elements_[last_] << endl;
	}
}