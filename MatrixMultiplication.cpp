//Author: Erin Murphy

#include "MatrixMultiplication.h"

//default constructor
MatrixMultiplication::MatrixMultiplication() {

	rowsA = 0;
	colsA = 0;
	rowsB = 0;
	colsB = 0;
	rowsP = 0;
	colsP = 0;
	product = 0;
}

//setting the value for matrix A rows
void MatrixMultiplication::setARows(int m) {

	rowsA = m;
}

//setting the value for matrix A columns
void MatrixMultiplication::setACols(int n) {

	colsA = n;
}

//setting the value for martrix B rows
void MatrixMultiplication::setBRows(int m) {
	 
	rowsB = m;
}

//setting the value for matrix B columns
void MatrixMultiplication::setBCols(int n) {
	 
	colsB = n;
}

//calculating the dimensions of the product matrix
bool  MatrixMultiplication::prodDimension() {

	//error checking if the matrix A columns and matrix B rows are not equal
	//returning true or false 
	if (colsA != rowsB)
		return false;

	//if true then calculate product matrix dimensions
	else {

		rowsP = rowsA;
		colsP = colsB;

		return true;
	}		
}

//printing out the matrices (for testing purposes only)
void MatrixMultiplication::printMatrix(){

	for (int i = 0; i < rowsA; i++) {

		for (int j = 0; j < colsA; j++) {

			cout << matrixA[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < rowsB; i++) {

		for (int j = 0; j < colsB; j++) {

			cout << matrixB[i][j] << " ";
		}

		cout << endl;
	}
}

//creating matrix A by adding the passed vector into the 2d vector
void MatrixMultiplication::createMatrixA(vector<int> m) {

	matrixA.push_back(m);
}

//creating matrix B by adding the passed vector into the 2d vector
void MatrixMultiplication::createMatrixB(vector<int> m) {

	matrixB.push_back(m);
}

//multiplying the matrices
void MatrixMultiplication::multiplyMatrices() {

	for (int i = 0; i < rowsA; i++) {

		prodMatrix.push_back(vector<int>(colsP));

		for (int j = 0; j < colsB; j++) {

			//initializing the vector position
			prodMatrix[i][j] = 0;

			for (int k = 0; k < colsA; k++) {

				//adding the result to the initialized position
				prodMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}

//displaying the product matrix
void MatrixMultiplication::displayProduct() {

	cout << setw(5);

	cout << "\n-- Result --\nMatrix multiplication of A and B:" << endl;

	for (int i = 0; i < rowsP; i++) {

		for (int j = 0; j < colsP; j++) {

			cout << setw(6);
			cout << prodMatrix[i][j];
		}	

		cout << endl;
	}	

	cout << "______________________________________________________________" << endl;
}