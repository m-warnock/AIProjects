#pragma once
#include "Definitions.h"

using namespace std;

int main() {
	int *coin_array = LoadFile(); // OR change so it returns array of coins
	cout << coin_array[5];
	system("pause");
	system("cls");
	cout << "Welcome!" << endl;
	system("pause");
	return 0;
}