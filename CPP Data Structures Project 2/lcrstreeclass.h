#ifndef _LCRS_TREE_
#define _LCRS_TREE_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct nodespace{
	string label;
};

struct cellspace{
	int leftmost_child;
	int right_sibling;
	int parent;
};

class lcrstree
{
private:
	int root_;
	vector<nodespace> nodespace_;
	vector<cellspace> cellspace_;
public:
	lcrstree();
	int PARENT(int x);
	int LEFTMOST_CHILD(int x);
	int RIGHT_SIBLING(int x);
	string LABEL(int x);
	void CREATE0(string label);
	void CREATE1(string label, lcrstree T1);
	void CREATE2(string label, lcrstree T1, lcrstree T2);
	void CREATE3(string label, lcrstree T1, lcrstree T2, lcrstree T3);
	int ROOT();
	void MAKENULL();
	void PRINT();
};

#endif