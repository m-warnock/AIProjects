// Michael Warnock ID: 16120478
// CS 461 Intro to Artificial Intelligence
// Prof: Brian Hare
// Project 1: Coin Game
// Due 3 September 2017


#include "Definitions.h"

fstream LoadFile(string filename) {

	fstream fhandle;
	fhandle.open(filename);
	
	if (fhandle.fail())
		cout << "Could not read game file." << endl;
	else
		return fhandle;
}