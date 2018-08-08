#ifndef _POINTER_STACK_
#define _POINTER_STACK_

#include <iostream>
using namespace std;

struct stacknode{ //node
	int element_; //data
	stacknode *next_; //pointer to next node
};

class pointerstack
{
private:
	stacknode *head; //header node
public:
	pointerstack();
	int TOP();
	int POP();
	void PUSH(int x);
	bool EMPTY();
	stacknode* MAKENULL();
	void PRINTLIST();
};

#endif