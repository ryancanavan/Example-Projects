using namespace std;
#include "lcrstreeclass.h"

//initializes by setting root to NULL
lcrstree::lcrstree(){}

//returns the parent value from the cellspace node corresponding to the input integer x
int lcrstree::PARENT(int x){
	return(cellspace_[x].parent);
}

//returns the leftmost child value from the cellspace node corresponding to the input integer x
int lcrstree::LEFTMOST_CHILD(int x){
	return(cellspace_[x].leftmost_child);
}

//returns the right sibling value from the cellspace node corresponding to the input integer x
int lcrstree::RIGHT_SIBLING(int x){
	return(cellspace_[x].right_sibling);
}

//returns the label value from the nodespace node corresponding to the input integer x
string lcrstree::LABEL(int x){
	return(nodespace_[x].label);
}

//creates a tree with just one node as the root with the label given by the input
void lcrstree::CREATE0(string label){
	root_ = 0; //sets root value
	nodespace tempnode;
	tempnode.label = label;
	nodespace_.push_back(tempnode); //sets roots label to input label
	cellspace tempcell;
	cellspace_.push_back(tempcell); //sets the leftmost child, right sibling, and parent data for the root
}

//creates a tree with the root node having the input label and one sibling which is the tree T1
void lcrstree::CREATE1(string label, lcrstree T1){
	root_ = T1.nodespace_.size();
	nodespace_.insert(nodespace_.end(), T1.nodespace_.begin(), T1.nodespace_.end()); //inserts the nodespace list into the new tree's nodespace list
	cellspace_.insert(cellspace_.end(), T1.cellspace_.begin(), T1.cellspace_.end());

	nodespace tempnode;
	tempnode.label = label;
	nodespace_.push_back(tempnode);
	cellspace tempcell;
	tempcell.leftmost_child = T1.nodespace_.size() - 1;
	cellspace_.push_back(tempcell);

	cellspace_[T1.nodespace_.size() - 1].parent = root_; //sets the root of T1 to have a parent value of the new root node
}

//creates a tree with the root node having the input label and two siblings which are the trees T1 and T2
void lcrstree::CREATE2(string label, lcrstree T1, lcrstree T2){
	root_ = T1.nodespace_.size() + T2.nodespace_.size();
	nodespace_.insert(nodespace_.end(), T1.nodespace_.begin(), T1.nodespace_.end());
	nodespace_.insert(nodespace_.end(), T2.nodespace_.begin(), T2.nodespace_.end());
	cellspace_.insert(cellspace_.end(), T1.cellspace_.begin(), T1.cellspace_.end());
	cellspace_.insert(cellspace_.end(), T2.cellspace_.begin(), T2.cellspace_.end());

	nodespace tempnode;
	tempnode.label = label;
	nodespace_.push_back(tempnode);
	cellspace tempcell;
	tempcell.leftmost_child = T1.nodespace_.size() - 1;
	cellspace_.push_back(tempcell);


	cellspace_[T1.nodespace_.size() - 1].right_sibling = T1.nodespace_.size() + T2.nodespace_.size() - 1; //sets T1's root to have a right sibling of T2's root
	cellspace_[T1.nodespace_.size() - 1].parent = root_;
	cellspace_[T1.nodespace_.size() + T2.nodespace_.size() - 1].parent = root_; //sets T1 and T2's roots' parents to the new root
}

	
void lcrstree::CREATE3(string label, lcrstree T1, lcrstree T2, lcrstree T3){
	root_ = T1.nodespace_.size() + T2.nodespace_.size() + T3.nodespace_.size();
	nodespace_.insert(nodespace_.end(), T1.nodespace_.begin(), T1.nodespace_.end());
	nodespace_.insert(nodespace_.end(), T2.nodespace_.begin(), T2.nodespace_.end());
	nodespace_.insert(nodespace_.end(), T3.nodespace_.begin(), T3.nodespace_.end());
	cellspace_.insert(cellspace_.end(), T1.cellspace_.begin(), T1.cellspace_.end());
	cellspace_.insert(cellspace_.end(), T2.cellspace_.begin(), T2.cellspace_.end());
	cellspace_.insert(cellspace_.end(), T3.cellspace_.begin(), T3.cellspace_.end());

	nodespace tempnode;
	tempnode.label = label;
	nodespace_.push_back(tempnode);
	cellspace tempcell;
	tempcell.leftmost_child = T1.nodespace_.size() - 1;
	cellspace_.push_back(tempcell);

	cellspace_[T1.nodespace_.size() - 1].right_sibling = T1.nodespace_.size() + T2.nodespace_.size() - 1;
	cellspace_[T1.nodespace_.size() + T2.nodespace_.size() - 1].right_sibling = T1.nodespace_.size() + T2.nodespace_.size() + T3.nodespace_.size() - 1;
	cellspace_[T1.nodespace_.size() - 1].parent = root_;
	cellspace_[T1.nodespace_.size() + T2.nodespace_.size() - 1].parent = root_;
	cellspace_[T1.nodespace_.size() + T2.nodespace_.size() + T3.nodespace_.size() - 1].parent = root_;
}

//returns the position of the root
int lcrstree::ROOT(){
	return(root_);
}

//clears the vectors and sets the root to null to make the tree clear
void lcrstree::MAKENULL(){
	nodespace_.clear();
	cellspace_.clear();
}

//prints out the tree values
void lcrstree::PRINT(){
	if (nodespace_.empty())
		cout << "empty" << endl;
	else{
		for (int i = 0; i < nodespace_.size(); i++){
			cout << nodespace_[i].label << " ";
		}
		cout << endl;
	}
}
