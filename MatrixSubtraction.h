#pragma once
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>

using namespace std;

class MatrixSubtraction {

private:
	int rows, diff;
	
	vector<int> matrixA;
	vector<int> matrixB;
	vector<int> diffMatrices;
	vector<int>::iterator it;

public:
	MatrixSubtraction();

	void setRows(int);
	void printMatrix();

	void createMatrixA(int);
	void createMatrixB(int);

	void subtractMatrices();
	void displayDifference();
};