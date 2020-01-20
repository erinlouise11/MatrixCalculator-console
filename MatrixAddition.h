#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>

using namespace std;

class MatrixAddition{

private:
	int rows, sum;
	vector<int> matrixA;
	vector<int> matrixB;
	vector<int> sumMatrices;
	vector<int>::iterator it;

public:
	MatrixAddition();

	void setRows(int);
	void printMatrix();

	void createMatrixA(int);
	void createMatrixB(int);

	void addMatrices();
	void displaySum();
};