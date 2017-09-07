#pragma once
#include "Definitions.h"

using namespace std;
	
int main() {
	vector<int> coin_vector = LoadFile(); 
	int** table = CreateMatrix(0, coin_vector.size());
	BuildTable(table, coin_vector);
	for (int i = 0; i < coin_vector.size(); i++) {
		for (int j = 0; j < coin_vector.size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	//cout << table[0][coin_array.size() - 1];
	system("pause");
	system("cls");
	PlayGame(coin_vector, table);
	system("pause");

	return 0;
}