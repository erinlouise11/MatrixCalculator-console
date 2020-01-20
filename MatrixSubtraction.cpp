//Author: Erin Murphy

#include "MatrixSubtraction.h"

//default constructor to initialize variables to 0
MatrixSubtraction::MatrixSubtraction(){

	rows = 0;
	diff = 0;
}

//assigning the value of matrix A and B rows
void MatrixSubtraction::setRows(int m){

	rows = m;
}

//printing the matrices (for test purposes only)
void MatrixSubtraction::printMatrix(){

	for (it = matrixA.begin(); it < matrixA.end(); it++) {

		cout << *it << " ";
	}

	cout << endl;

	for (it = matrixB.begin(); it < matrixB.end(); it++) {

		cout << *it << " ";
	}

	cout << endl;

	for (it = diffMatrices.begin(); it < diffMatrices.end(); it++) {

		cout << *it << " ";
	}
}

//adding the passed elements to the vector for matrix A
void MatrixSubtraction::createMatrixA(int e){

	matrixA.push_back(e);
}

//adding the passed elements to the vector for matrix B
void MatrixSubtraction::createMatrixB(int e){

	matrixB.push_back(e);
}

//subtracting the matrices
void MatrixSubtraction::subtractMatrices(){

	for (int i = 0; i < matrixA.size(); i++) {

		//adding the result to the vector holding the difference of the two matrices
		diff = (matrixA[i] - matrixB[i]);
		diffMatrices.push_back(diff);
	}
}

//displaying the result matrix
void MatrixSubtraction::displayDifference(){

	int count = 1;
	cout << "\n-- Result --\nDifference of A and B:" << endl;

	//getting the matrix to print in a 2D format
	//using a counter variable to count the end of the row and reset
	//even number of rows
	if (rows % 2 == 0) {

		for (int i = 0; i < diffMatrices.size(); i++) {

			if (count % rows == 0) {

				cout << setw(6);
				cout << diffMatrices[i] << endl;
				count == 0;
			}

			else {

				cout << setw(6);
				cout << diffMatrices[i];
			}

			count++;
		}
	}

	//odd number or rows
	if (rows % 2 != 0) {

		for (int i = 0; i < diffMatrices.size(); i++) {

			if (count % rows == 0) {

				cout << setw(6);
				cout << diffMatrices[i] << endl;
			}

			else {

				cout << setw(6);
				cout << diffMatrices[i];
			}				

			count++;
		}
	}

	cout << "______________________________________________________________" << endl;
}