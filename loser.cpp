/*
 * hw6.cpp
 *
 *  Created on: Oct 18, 2017
 *      Author: andrewratz
 */

#include <iostream>
#include "hw6.h"

using namespace std;
using namespace cop3530;

int main() {
	int int_scores[] = {4, 3, 6, 8, 1, 5, 7, 3, 2, 6, 9, 4, 5, 2, 5, 8};
	size_t size = sizeof(int_scores)/sizeof(int);
	ADTLoserTree<int>* int_Tree = new ADTLoserTree<int>(size);
	int_Tree->create(int_scores);
	cout << "---Testing the size of backing array---" << endl;
	cout << "Size of scores array: " << int_Tree->size() << endl;
	cout << "---Testing the tournament function that returns the loser tree packed array---" << endl;
		cout << "This is the scores array: ";
	for (int i = 0; i < size; i++) {
		cout << int_scores[i];
	}
	cout << endl;
	int* int_loser_tree = int_Tree->tournament();
	cout << "This is the returned Loser Tree: ";
	for (int i = 0; i < size; i++) {
		cout << *int_loser_tree;
		int_loser_tree++;
	}
	cout << endl << endl;

	cout << "---ERROR: Testing the built-in print function of ADTLoserTree---" << endl;
	int_Tree->print();
	cout << "It fails because tournament() is messing up the starting scores array on subsequent runs" << endl << endl;

	cout << "However, reinitializing with a copy of the starting array does work correctly" << endl;
	cout << "---Testing the built-in print function of ADTLoserTree---" << endl;
	int int_scores2[] = {4, 3, 6, 8, 1, 5, 7, 3, 2, 6, 9, 4, 5, 2, 5, 8};
	int_Tree->create(int_scores2);
	int_Tree->print();
	cout << endl;

	cout << "---Testing the winner function of ADTLoserTree---" << endl;
	int int_scores3[] = {4, 3, 6, 8, 1, 5, 7, 3, 2, 6, 9, 4, 5, 2, 5, 8};
	int_Tree->create(int_scores3);
	cout << "The winner is: " << int_Tree->winner() << endl << endl;

	cout << "---Testing an array with a size not divisible by 4---" << endl;
	int int_scores4[] = {7, 3, 1, 4, 5, 8};
	size = sizeof(int_scores4)/sizeof(int);
	ADTLoserTree<int>* int_Tree4 = new ADTLoserTree<int>(size);
	int_Tree4->create(int_scores4);
	int_Tree4->print();
	cout << endl;

	cout << "---ERROR: Testing the sort function of ADTLoserTree---" << endl;
	int int_scores5[] = {4, 3, 6, 8, 1, 5, 7, 3, 2, 6, 9, 4, 5, 2, 5, 8};
	int_Tree->create(int_scores5);
	int* sorted = int_Tree->sort();
	for (int i = 0; i < size; i++) {
		cout << *sorted;
		sorted++;
	}
	cout << endl << endl;
}























