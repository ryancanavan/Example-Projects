#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <iostream>
using namespace std;

class arraystack
{
private:
	static const int maxLength = 10000; //max size of list
	int elements_[maxLength]; //data
	int top_; //position of top of stack(most recent element in)
public:
	arraystack();
	int TOP();
	int POP();
	void PUSH(int x);
	bool EMPTY();
	int MAKENULL();
	void PRINTLIST();
};

#endif