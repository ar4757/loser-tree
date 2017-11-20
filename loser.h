/*
 * hw6.h
 *
 *  Created on: Oct 18, 2017
 *      Author: andrewratz
 */

#ifndef HW6_H_
#define HW6_H_

#include <cstdio>
using namespace std;

namespace cop3530 {
	//Template of class T, standing for "element"
	template <class T>
	class ADTLoserTree {
	public:
		T* scores = nullptr;
		size_t scores_size;
		ADTLoserTree(size_t array_size) {
			scores_size = array_size;
		}
		~ADTLoserTree() {

		}
		void create(T *array) {
			scores = array;
		}
		size_t size() {
			return scores_size;
		}
		//Prints the scoreboard and loser tree
		void print() {
			if (scores == nullptr) {
				cout << "Please create the tree before trying to print";
			}
			else {
				//Outputs the scoreboard
				T* temp = scores;
				cout << "Scores: ";
				for (int i = 0; i < size(); i++) {
					cout << *temp;
					temp++;
				}
				cout << endl;
				//Outputs the loser tree
				temp = tournament();
				cout << "Loser Tree: ";
				for (int i = 0; i < size(); i++) {
					cout << *temp;
					temp++;
				}
				cout << endl;
			}
			return;
		}
		//Returns an array representation of the loser tree
		T* tournament() {
			T* scores_bak = scores;
			int counter = size();
			T* tree = new T[counter];
			//i is used for getting score values
			int i = 0;
			//j indicates the current index of the loser tree packed array, and starts halfway through it, since the bottom layer of a tree will contain exactly or just under half the elements
			int j = counter/2;
			//k is used when updating the current score array
			int k = 0;
			//fills the back half of the array with the greater values, then repeatedly fills more and more toward the front of the array
			while (i < counter - 1) {
				//left greater than right
				if (scores_bak[i] > scores_bak[i+1]) {
					//puts the greater value into the tree array
					tree[j] = scores_bak[i];
					//puts the lesser value to the first available slot of the scores array
					scores_bak[k] = scores_bak[i+1];
				}
				//right greater than or equal to left
				else {
					tree[j] = scores_bak[i+1];
					scores_bak[k] = scores_bak[i];
				}
				//just before the while loop would end
				if (i+2 >= counter) {
					//halve the size of the score array to navigate
					counter = counter/2;
					//reset i to 0, since the score array's values were updating starting at [0]
					i = 0;
					//j now starts closer to the front of the tree array
					j = (counter/2);
					//reset k to 0
					k = 0;
					continue;
				}
				//i increases by 2 because i and i+1 are being compared
				i+=2;
				j++;
				k++;
			}
			//Final step, sets the root to the overall least value (counter eventually gets to 1, then i = 0 < counter - 1 is false, causing the loop to break with the correct i and j values)
			tree[j] = scores_bak[i];
			//Fixes the first index in even trees that aren't divisble by 4
			if (size() % 4 == 2) {
				tree[0] = scores_bak[0];
			}
			//The tree is now complete, and ready to be returned
			return tree;
		}
		//Returns the winner
		T winner() {
			T* loser_tree = tournament();
			T winner = *loser_tree;
			return winner;
		}
		//Updates a player's score
		void update(T player, T updated) {
			for (int i = 0; i < size(); i++) {
				if (*scores == player) {
					*scores = updated;
					return;
				}
			}
			return;
		}
		//Removes a player
		void eliminate(T player) {
			//The updated scoreboard will have one less player
			T* new_scores = new T[size()-1];
			//j keeps track of the new array's index
			int j = 0;
			//i keeps track of the old array's index (it always increments)
			for (int i = 0; i < size(); i++) {
				if (*scores == player) {
					continue;
				}
				else {
					new_scores[j] = scores[i];
					//j only increments if the player was not eliminated
					j++;
				}
			}
			//Sets the current array to the new scoreboard
			scores = new_scores;
			return;
		}
		T* sort() {
			T* sorted = new T[size()];
			T current = winner();
			//Doesn't work yet so capping the loop
			int i = 0;
			while (current < 1000000 && i < size()) {
				*sorted = current;
				update(current, 1000000);
				tournament();
				current = winner();
				i++;
			}
			return sorted;
		}
	};

}

#endif /* HW6_H_ */
