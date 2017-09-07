// Michael Warnock ID: 16120478
// CS 461 Intro to Artificial Intelligence
// Prof: Brian Hare
// Project 1: Coin Game
// Due 3 September 2017


#include "Definitions.h"

vector<int> LoadFile() {

	
	vector<int> coin_line;
	bool good_file = false;

	while (!good_file) {
		string filename;
		fstream fhandle;
		cout << "Enter a properly formatted game file (.txt):" << endl;
		cin >> filename;
		fhandle.open(filename);

		if (filename == "exit")
			exit(EXIT_FAILURE);

		if (!fhandle.good()) {
			cout << endl << "Could not read game file." << endl
				<< "Try another file or type 'exit' to exit." << endl << endl;
			continue;
		}
		
		int arraysize = -1; //initial state
		fhandle >> arraysize; //gets the number of coins

		if (arraysize == -1)
			cout << "That file is empty" << endl;

		else if (arraysize % 2 == 0) {  // check for even
			vector<int> coin_array;
			int single_coin;

			for (int i = 0; i < arraysize; i++) { // fill array from file
				fhandle >> single_coin;
				coin_array.push_back(single_coin);
				}

			coin_line = coin_array;
			good_file = true;
			cout << endl << "Success!" << endl;			
		}
		
		else
			cout << endl << "There must be an even number of coins!" << endl << endl
			<< "Try another file or type 'exit' to exit." << endl << endl;
		}

	return coin_line;
}


//creates a square int matrix
// copy pasted from one of my older projects

int** CreateMatrix(int initialvalue, int size) {
	int** Matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		Matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			Matrix[i][j] = initialvalue;
		}
	}
	return Matrix;
}


// Creates the table for best possible garunteed outcome for any line of coins
void BuildTable(int** &table, vector<int> coin_vector) {
	
	int n, gap, i, j, x, y, z;
	n = coin_vector.size();
	for(gap = 0; gap < n; gap++){
		
		for (i = 0, j = gap; j < n; i++, j++) {

			x = ((i + 2) <= j) ? table[i + 2][j] : 0;
			y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
			z = (i <= (j - 2)) ? table[i][j - 2] : 0;

			table[i][j] = max(coin_vector[i] + min(x, y), coin_vector[j] + min(y, z));
		}
	}
}


void PlayGame(vector<int> coin_vector, int** table) {
	
	bool game_over = false;
	//initialize begin/end indices of playable coin line
	int left = 0;
	int right = coin_vector.size() - 1;
	char choice;
	int human_score = 0;
	int computer_score = 0;
	
	cout << "Welcome to the coin game!" << endl << endl;
	while (game_over != true) {
		
		cout << "Your Turn!" << endl;

		//print coins to console
		for (int i = left; i <= right; i++) {
			cout << coin_vector[i] << " ";
		}
		cout << endl;
		
		//get user's choice and validate input
		bool good_input = false;
		while (!good_input) {
			
			cout << "\nChoose a coin (l for left, r for right): ";
			cin >> choice;
			choice = tolower(choice);
			
			if (choice == 'l') {
				human_score += coin_vector[left];
				left++;
				good_input = true;
			}
			else if (choice == 'r') {
				human_score += coin_vector[right];
				right--;
				good_input = true;
			}
			else
				cout << "Please enter an 'l' or 'r'." << endl;
				

		}

		cout << endl << "My Turn!" << endl;

		for (int i = left; i <= right; i++) {
			cout << coin_vector[i] << " ";
		}
		cout << endl;

		// computer choses by subtracting left/right options from calculated table values. 
		// It is like this because the table is calculated all at once.
		if ((table[left][right] - coin_vector[left]) < (table[left][right] - coin_vector[right])) {
			//computer chooses left
			computer_score += coin_vector[left];
			cout << "I choose " << coin_vector[left] << ", the left coin!" << endl << endl;
			left++;
		}
		else {
			//computer chooses right
			computer_score += coin_vector[right];
			cout << "I choose " << coin_vector[right] << ", the right coin!" << endl << endl;
			right--;
		}

		//cout << table[left][right] << endl << endl;
		if (left >= right) {
			game_over = true;

			cout << "Your Score: " << human_score << endl;
			cout << "Computer Score: " << computer_score << endl;

			if (human_score > computer_score)
				cout << endl << "You WIN!" << endl;
			else if (human_score == computer_score)
				cout << endl << "DRAW!" << endl;
			else
				cout << endl << "You LOSE!" << endl;
		}
		
		//computer always gets last score
		
	}
	
}