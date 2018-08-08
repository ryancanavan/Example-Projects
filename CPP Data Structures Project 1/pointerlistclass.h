#ifndef _POINTER_LIST_
#define _POINTER_LIST_

#include <iostream>
using namespace std;

struct listnode{ //node
	int element_; //data
	listnode *next_; //pointer to next node
};

class pointerlist
{
private:
	listnode *head; //header node
public:
	pointerlist();
	listnode* FIRST();
	listnode* END();
	int RETRIEVE(listnode* p);
	int LOCATE(int x);
	listnode* NEXT(listnode* p);
	listnode* PREVIOUS(listnode* p);
	void INSERT(int x, listnode *p);
	void DELETE(listnode* p);
	listnode* MAKENULL();
	void PRINTLIST();
};

#endif