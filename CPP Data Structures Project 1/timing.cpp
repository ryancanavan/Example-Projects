#include <iostream>
#include <ctime>
#include <list>
#include <stack>
using namespace std;
#include "arraylistclass.h"
#include "pointerlistclass.h"
#include "arraystackclass.h"
#include "pointerstackclass.h"

int main(){
	arraylist al;
	pointerlist pl;
	list<int> intList;

	clock_t alStart, alStop, plStart, plStop, ilStart, ilStop;

	alStart = clock();
	for (int i = 10000; i > 0; i--)
		al.INSERT(i, al.FIRST());
	alStop = clock();

	plStart = clock();
	for (int i = 10000; i > 0; i--)
		pl.INSERT(i, pl.FIRST());
	plStop = clock();

	ilStart = clock();
	for (int i = 1; i <= 10000; ++i)
		intList.push_front(i);
	ilStop = clock();

	cout << "----------FRONT INSERTION----------" << endl;
	double alFrontTimeTaken = (1000 * ((double)alStop - alStart) / CLOCKS_PER_SEC);
	double plFrontTimeTaken = (1000 * ((double)plStop - plStart) / CLOCKS_PER_SEC);
	double ilFrontTimeTaken = (1000 * ((double)ilStop - ilStart) / CLOCKS_PER_SEC);
	cout << "Time taken to populate the array list " << alFrontTimeTaken << " milliseconds" << endl;
	cout << "Time taken to populate the pointer list " << plFrontTimeTaken << " milliseconds" << endl;
	cout << "Time taken to populate the built-in list " << ilFrontTimeTaken << " milliseconds" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////
	al.MAKENULL();
	pl.MAKENULL();
	intList.clear();
////////////////////////////////////////////////////////////////////////////////////////////////////////
	alStart = clock();
	for (int i = 10000; i > 0; i--)
		al.INSERT(i, al.END());
	alStop = clock();

	plStart = clock();
	for (int i = 10000; i > 0; i--)
		pl.INSERT(i, pl.END());
	plStop = clock();

	ilStart = clock();
	for (int i = 1; i <= 10000; ++i)
		intList.push_back(i);
	ilStop = clock();

	cout << "----------BACK INSERTION----------" << endl;
	double alBackTimeTaken = (1000 * ((double)alStop - alStart) / CLOCKS_PER_SEC);
	double plBackTimeTaken = (1000 * ((double)plStop - plStart) / CLOCKS_PER_SEC);
	double ilBackTimeTaken = (1000 * ((double)ilStop - ilStart) / CLOCKS_PER_SEC);
	cout << "Time taken to populate the array list " << alBackTimeTaken << " milliseconds" << endl;
	cout << "Time taken to populate the pointer list " << plBackTimeTaken << " milliseconds" << endl;
	cout << "Time taken to populate the built-in list " << ilBackTimeTaken << " milliseconds" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////
	alStart = clock();
	int alTrav = al.FIRST();
	for (int i = 10000; i > 0; i--)
		alTrav = al.NEXT(alTrav);
	alStop = clock();

	plStart = clock();
	listnode *plTrav = pl.FIRST();
	for (int i = 10000; i > 0; i--)
		plTrav = pl.NEXT(plTrav);
	plStop = clock();

	ilStart = clock();
	for (list<int>::iterator it = intList.begin(); it != intList.end(); ++it)
		*it;
	ilStop = clock();

	cout << "----------TRAVERSAL----------" << endl;
	double alTravTimeTaken = (1000 * ((double)alStop - alStart) / CLOCKS_PER_SEC);
	double plTravTimeTaken = (1000 * ((double)plStop - plStart) / CLOCKS_PER_SEC);
	double ilTravTimeTaken = (1000 * ((double)ilStop - ilStart) / CLOCKS_PER_SEC);
	cout << "Time taken to traverse the array list " << alTravTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the pointer list " << plTravTimeTaken << " milliseconds" << endl;
	cout << "Time taken to traverse the built-in list " << ilTravTimeTaken << " milliseconds" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////
	alStart = clock();
	for (int i = 10000; i > 0; i--)
		al.DELETE(al.FIRST());
	alStop = clock();

	plStart = clock();
	for (int i = 10000; i > 0; i--)
		pl.DELETE(pl.FIRST());
	plStop = clock();

	ilStart = clock();
	for (int i = 1; i <= 10000; ++i)
		intList.pop_back();
	ilStop = clock();

	cout << "----------FRONT DELETION----------" << endl;
	double alFrontDelTimeTaken = (1000 * ((double)alStop - alStart) / CLOCKS_PER_SEC);
	double plFrontDelTimeTaken = (1000 * ((double)plStop - plStart) / CLOCKS_PER_SEC);
	double ilFrontDelTimeTaken = (1000 * ((double)ilStop - ilStart) / CLOCKS_PER_SEC);
	cout << "Time taken to delete the array list " << alFrontDelTimeTaken << " milliseconds" << endl;
	cout << "Time taken to delete the pointer list " << plFrontDelTimeTaken << " milliseconds" << endl;
	cout << "Time taken to delete the built-in list " << ilFrontDelTimeTaken << " milliseconds" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 10000; i > 0; i--)
		al.INSERT(i, al.FIRST());
	for (int i = 10000; i > 0; i--)
		pl.INSERT(i, pl.FIRST());
	for (int i = 1; i <= 10000; ++i)
		intList.push_front(i);
////////////////////////////////////////////////////////////////////////////////////////////////////////
	alStart = clock();
	for (int i = 10000; i > 0; i--)
		al.DELETE(al.PREVIOUS(al.END()));
	alStop = clock();

	plStart = clock();
	for (int i = 9999; i > 0; i--)
		pl.DELETE(pl.PREVIOUS(pl.PREVIOUS(pl.END())));
	pl.DELETE(pl.PREVIOUS(pl.END()));
	plStop = clock();

	ilStart = clock();
	for (int i = 1; i <= 10000; ++i)
		intList.pop_front();
	ilStop = clock();

	cout << "----------BACK DELETION----------" << endl;
	double alBackDelTimeTaken = (1000 * ((double)alStop - alStart) / CLOCKS_PER_SEC);
	double plBackDelTimeTaken = (1000 * ((double)plStop - plStart) / CLOCKS_PER_SEC);
	double ilBackDelTimeTaken = (1000 * ((double)ilStop - ilStart) / CLOCKS_PER_SEC);
	cout << "Time taken to delete the array list " << alBackDelTimeTaken << " milliseconds" << endl;
	cout << "Time taken to delete the pointer list " << plBackDelTimeTaken << " milliseconds" << endl;
	cout << "Time taken to delete the built-in list " << ilBackDelTimeTaken << " milliseconds" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////
	arraystack as;
	pointerstack ps;
	stack<int> intStack;

	clock_t asStart, asStop, psStart, psStop, isStart, isStop;

	asStart = clock();
	for (int i = 10000; i > 0; i--)
		as.PUSH(i);
	asStop = clock();

	psStart = clock();
	for (int i = 10000; i > 0; i--)
		ps.PUSH(i);
	psStop = clock();

	isStart = clock();
	for (int i = 1; i <= 10000; ++i)
		intStack.push(i);
	isStop = clock();

	cout << "----------STACK PUSH----------" << endl;
	double asPushTimeTaken = (1000 * ((double)asStop - asStart) / CLOCKS_PER_SEC);
	double psPushTimeTaken = (1000 * ((double)psStop - psStart) / CLOCKS_PER_SEC);
	double isPushTimeTaken = (1000 * ((double)isStop - isStart) / CLOCKS_PER_SEC);
	cout << "Time taken to push onto the array stack " << asPushTimeTaken << " milliseconds" << endl;
	cout << "Time taken to push onto the pointer stack " << psPushTimeTaken << " milliseconds" << endl;
	cout << "Time taken to push onto the built-in stack " << isPushTimeTaken << " milliseconds" << endl;
////////////////////////////////////////////////////////////////////////////////////////////////////////
	asStart = clock();
	for (int i = 10000; i > 0; i--)
		as.POP();
	asStop = clock();

	psStart = clock();
	for (int i = 10000; i > 0; i--)
		ps.POP();
	psStop = clock();

	isStart = clock();
	for (int i = 1; i <= 10000; ++i)
		intStack.pop();
	isStop = clock();

	cout << "----------STACK POP----------" << endl;
	double asPopTimeTaken = (1000 * ((double)asStop - asStart) / CLOCKS_PER_SEC);
	double psPopTimeTaken = (1000 * ((double)psStop - psStart) / CLOCKS_PER_SEC);
	double isPopTimeTaken = (1000 * ((double)isStop - isStart) / CLOCKS_PER_SEC);
	cout << "Time taken to push onto the array stack " << asPopTimeTaken << " milliseconds" << endl;
	cout << "Time taken to push onto the pointer stack " << psPopTimeTaken << " milliseconds" << endl;
	cout << "Time taken to push onto the built-in stack " << isPopTimeTaken << " milliseconds" << endl;

	return 0;
}