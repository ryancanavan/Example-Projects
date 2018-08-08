#ifndef _LOC_TREE_
#define _LOC_TREE_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct locnode{
	string label;
	vector<locnode> LIST_;
	int position_;
};

class loctree
{
private:
	vector<locnode> header;
	locnode root;
public:
	loctree();
	locnode PARENT(locnode x);
	locnode LEFTMOST_CHILD(locnode x);
	locnode RIGHT_SIBLING(locnode x);
	string LABEL(locnode x);
	loctree CREATE0(string label);
	loctree CREATE1(string label, loctree T1);
	loctree CREATE2(string label, loctree T1, loctree T2);
	loctree CREATE3(string label, loctree T1, loctree T2, loctree T3);
	locnode ROOT();
	void MAKENULL();
	void PRINT();
};

#endif