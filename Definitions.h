#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<int> LoadFile(); //returns filehandle for given filename
int** CreateMatrix(int initialvalue, int size);
void BuildTable(int** &table, vector<int> coin_vector); //populate dynamic programming table
inline int max(int a, int b) { return a > b ? a : b; };
inline int min(int a, int b) { return a < b ? a : b; };
void PlayGame(vector<int> coin_vector, int** table);