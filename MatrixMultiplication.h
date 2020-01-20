#pragma once
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class MatrixMultiplication{

private:
	int rowsA, colsA, rowsB, colsB, rowsP, colsP, product;

	vector<vector<int> > matrixA;
	vector<vector<int> > matrixB;
	vector<vector<int> > prodMatrix;

public:
	MatrixMultiplication();

	void setARows(int);
	void setACols(int);
	void setBRows(int);
	void setBCols(int);
	bool prodDimension();
	void printMatrix();

	void createMatrixA(vector<int>);
	void createMatrixB(vector<int>);

	void multiplyMatrices();
	void displayProduct();
};