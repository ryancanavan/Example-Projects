#include <iostream>
#include <array>
using namespace std;
#include "arraylistclass.h"
#include "pointerlistclass.h"

//merges the a and b pointerlists into the result input and keeps them sorted
void sortedMerge(pointerlist a, pointerlist b, pointerlist &result){
	if (a.FIRST() == NULL && b.FIRST() == NULL){ //finish when both are empty
		return;
	}
	else if (a.FIRST() == NULL && b.FIRST() != NULL){ //if a is empty then dump the rest of b into result
		result.INSERT(b.RETRIEVE(b.FIRST()), result.END());
		b.DELETE(b.FIRST());
		sortedMerge(a, b, result);
	}
	else if (a.FIRST() != NULL && b.FIRST() == NULL){ //if b is empty then dump the rest of a into the result
		result.INSERT(a.RETRIEVE(a.FIRST()), result.END());
		a.DELETE(a.FIRST());
		sortedMerge(a, b, result);
	}
	else if (a.RETRIEVE(a.FIRST()) <= b.RETRIEVE(b.FIRST())){ //if a's first elmnt is less than b's, add it to result
		result.INSERT(a.RETRIEVE(a.FIRST()), result.END());
		a.DELETE(a.FIRST());
		sortedMerge(a, b, result);
	}
	else{ //if b's first elmnt is less than a's, add it to result
		result.INSERT(b.RETRIEVE(b.FIRST()), result.END());
		b.DELETE(b.FIRST());
		sortedMerge(a, b, result);
	}
}

void sortedAMerge(arraylist a, arraylist b, arraylist &result){ //same as above, but for arraylists
	if (a.END() == 0 && b.END() == 0){
		return;
	}
	else if (a.END() == 0 && b.END() != 0){
		result.INSERT(b.RETRIEVE(b.FIRST()), result.END());
		b.DELETE(b.FIRST());
		sortedAMerge(a, b, result);
	}
	else if (a.END() != 0 && b.END() == 0){
		result.INSERT(a.RETRIEVE(a.FIRST()), result.END());
		a.DELETE(a.FIRST());
		sortedAMerge(a, b, result);
	}
	else if (a.RETRIEVE(a.FIRST()) <= b.RETRIEVE(b.FIRST())){
		result.INSERT(a.RETRIEVE(a.FIRST()), result.END());
		a.DELETE(a.FIRST());
		sortedAMerge(a, b, result);
	}
	else{
		result.INSERT(b.RETRIEVE(b.FIRST()), result.END());
		b.DELETE(b.FIRST());
		sortedAMerge(a, b, result);
	}
}

pointerlist mergeNLists(pointerlist arr[], int n){ //takes in an array of pointerlists and n which is the size of the array
	pointerlist combo, temp;
	for (int i = 0; i < n; i++){ //merges all of the lists
		temp = combo;
		combo.MAKENULL();
		sortedMerge(temp, arr[i], combo);
	}
	return(combo);
}

arraylist mergeNALists(arraylist arr[], int n){ //same as above but for arraylists
	arraylist combo, temp;
	for (int i = 0; i < n; i++){
		temp = combo;
		combo.MAKENULL();
		sortedAMerge(temp, arr[i], combo);
	}
	return(combo);
}

int main(){
	pointerlist l1, l2, l3, l4, l5, lcombo;
	pointerlist arr[5];
	for (int i = 10; i > 0; i--){ //create 5 lists to merge
		l1.INSERT(i, l1.FIRST());
	}
	for (int i = 20; i > 10; i--){
		l2.INSERT(i, l2.FIRST());
	}
	for (int i = 30; i > 20; i--){
		l3.INSERT(i, l3.FIRST());
	}
	for (int i = 40; i > 30; i--){
		l4.INSERT(i, l4.FIRST());
	}
	for (int i = 50; i > 40; i--){
		l5.INSERT(i, l5.FIRST());
	}
	cout << "My original pointer lists are: " << endl;
	l1.PRINTLIST();
	l2.PRINTLIST();
	l3.PRINTLIST();
	l4.PRINTLIST();
	l5.PRINTLIST();
	arr[0] = l1; //add the lists to an array
	arr[1] = l2;
	arr[2] = l3;
	arr[3] = l4;
	arr[4] = l5;
	lcombo = mergeNLists(arr, 5);
	cout << "My merged pointer list is: " << endl;
	lcombo.PRINTLIST();

////////////////////////////////////////////////////////////////////////////////

	arraylist l6, l7, l8, l9, l10, lc;
	arraylist ararr[5];
	for (int i = 10; i > 0; i--){ //create 5 more lists
		l6.INSERT(i, l6.FIRST());
	}
	for (int i = 20; i > 10; i--){
		l7.INSERT(i, l7.FIRST());
	}
	for (int i = 30; i > 20; i--){
		l8.INSERT(i, l8.FIRST());
	}
	for (int i = 40; i > 30; i--){
		l9.INSERT(i, l9.FIRST());
	}
	for (int i = 50; i > 40; i--){
		l10.INSERT(i, l10.FIRST());
	}
	cout << "My original array lists are: " << endl;
	l6.PRINTLIST();
	l7.PRINTLIST();
	l8.PRINTLIST();
	l9.PRINTLIST();
	l10.PRINTLIST();
	ararr[0] = l6; //add lists to array
	ararr[1] = l7;
	ararr[2] = l8;
	ararr[3] = l9;
	ararr[4] = l10;
	lc = mergeNALists(ararr, 5);
	cout << "My merged array list is: " << endl;
	lc.PRINTLIST();
	
	return 0;
}
