using namespace std;
#include "loctreeclass.h"

//initializes tree by setting root position to NULL
loctree::loctree(){
	locnode null;
	root = null;
}

//searches the header list and all of the children lists to find the parent of x
locnode loctree::PARENT(locnode x){
	for(int i = x.position_; i < header.size(); i++){ //searches header list
		for (int k = 0; k < header[i].LIST_.size(); k++){ //searches each header element's LIST_
			if (header[i].LIST_[k].position_ == x.position_)
				return header[i];
		}
	}
}

//returns the first element of the node x's LIST_
locnode loctree::LEFTMOST_CHILD(locnode x){
	return(x.LIST_.front());
}

//finds the PARENT value and returns the next element in the LIST_ of the parent
locnode loctree::RIGHT_SIBLING(locnode x){
	for (int i = 0; i < PARENT(x).LIST_.size(); i++){ //searches the parent LIST_
		if (PARENT(x).LIST_[i].position_ > x.position_)
			return(PARENT(x).LIST_[i]);
	}
}

//returns the label and x's position
string loctree::LABEL(locnode x){
	return(x.label);
}

//creates a tree with just one node as the root with the label given by the input
loctree loctree::CREATE0(string label){
	loctree tree;
	locnode r;
	r.position_ = 0;
	r.LIST_.clear();
	r.label = label;
	tree.root = r;
	tree.header.push_back(tree.root);
	return(tree);
}

//creates a tree with the root node having the input label and one sibling which is the tree T1
loctree loctree::CREATE1(string label, loctree T1){
	loctree tree;
	locnode r;
	for (int i = 0; i < T1.header.size(); i++){ //adds the headers and labels from T1 to the new tree
		tree.header.push_back(T1.header[i]);
	}
	r.LIST_.push_back(T1.root);
	r.position_ = tree.header.size();
	r.label = label;
	tree.root = r;
	tree.header.push_back(tree.root);
	return(tree);
}

//creates a tree with the root node having the input label and two siblings which are the trees T1 and T2
loctree loctree::CREATE2(string label, loctree T1, loctree T2){
	loctree tree;
	locnode r;
	for (int i = 0; i < T1.header.size(); i++){
		tree.header.push_back(T1.header[i]);
	}
	for (int i = 0; i < T2.header.size(); i++){
		tree.header.push_back(T2.header[i]);
	}
	for (int i = 0; i < tree.header.size(); i++){ //updates the positions of the nodes to their new values
		tree.header[i].position_ = i;
	}
	r.LIST_.push_back(T1.root);
	r.LIST_.push_back(T2.root);
	r.position_ = tree.header.size();
	r.label = label;
	tree.root = r;
	tree.header.push_back(tree.root);
	return(tree);
}

//creates a tree with the root node having the input label and three siblings which are the trees T1, T2, and T3
loctree loctree::CREATE3(string label, loctree T1, loctree T2, loctree T3){
	loctree tree;
	locnode r;
	for (int i = 0; i < T1.header.size(); i++){
		tree.header.push_back(T1.header[i]);
	}
	for (int i = 0; i < T2.header.size(); i++){
		tree.header.push_back(T2.header[i]);
	}
	for (int i = 0; i < T3.header.size(); i++){
		tree.header.push_back(T3.header[i]);
	}
	for (int i = 0; i < tree.header.size(); i++){
		tree.header[i].position_ = i;
	}
	r.LIST_.push_back(T1.root);
	r.LIST_.push_back(T2.root);
	r.LIST_.push_back(T3.root);
	r.position_ = tree.header.size();
	r.label = label;
	tree.root = r;
	tree.header.push_back(tree.root);
	return(tree);
}

//returns the root node
locnode loctree::ROOT(){
	return(root);
}

//clears the vectors and sets the root to a null node
void loctree::MAKENULL(){
	locnode null;
	header.clear();
	root = null;
}

//prints out the tree values
void loctree::PRINT(){
	if (header.empty())
		cout << "empty" << endl;
	else{
		for (int i = 0; i < header.size(); i++){
			cout << header[i].label << " ";
		}
		cout << endl;
	}
}