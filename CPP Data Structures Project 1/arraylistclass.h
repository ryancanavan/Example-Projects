#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

#include <iostream>
using namespace std;

class arraylist
{
private:
	static const int maxLength = 10000; //max size of list
	int elements_[maxLength]; //data
	int last_; //position of last element
public:
	arraylist();
	int FIRST();
	int END();
	int RETRIEVE(int p);
	int LOCATE(int x);
	int NEXT(int p);
	int PREVIOUS(int p);
	void INSERT(int x, int p);
	void DELETE(int p);
	int MAKENULL();
	void PRINTLIST();
};

#endif