// Michael Warnock ID: 16120478
// CS 461 Intro to Artificial Intelligence
// Prof: Brian Hare
// Project 1: Coin Game
// Due 3 September 2017


#include "Definitions.h"

int* LoadFile() {

	
	int* coin_line = 0;
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
			int* coin_array = NULL;
			coin_array = new int[arraysize]; //create array to hold coins
			int single_coin;

			for (int i = 0; i < arraysize; i++) { // fill array from file
				fhandle >> single_coin;
				coin_array[i] = single_coin;
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
	
	