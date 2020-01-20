//Author: Erin Murphy

#include "MatrixAddition.h"

//default constructor to initialize variables to 0
MatrixAddition::MatrixAddition(){

	rows = 0;
	sum = 0;
}

//assigning the value of matrix A and B rows
void MatrixAddition::setRows(int m){

	rows = m;
}

//printing the matrices (for test purposes only)
void MatrixAddition::printMatrix(){

	for (it = matrixA.begin(); it < matrixA.end(); it++) {

		cout << *it << " ";
	}

	cout << endl;

	for (it = matrixB.begin(); it < matrixB.end(); it++) {

		cout << *it << " ";
	}

	cout << endl;

	for (it = sumMatrices.begin(); it < sumMatrices.end(); it++) {

		cout << *it << " ";
	}
}

//adding the passed elements to the vector for matrix A
void MatrixAddition::createMatrixA(int element){

	matrixA.push_back(element);
}

//adding the passed elements to the vector for matrix B
void MatrixAddition::createMatrixB(int element){

	matrixB.push_back(element);
}

//adding the matrices 
void MatrixAddition::addMatrices(){
	
	for (int i = 0; i < matrixA.size(); i++) {

		//adding the result to the vector holding the sum of the two matrices
		sum = (matrixA[i] + matrixB[i]);		
		sumMatrices.push_back(sum);
	}
}

//displaying the result matrix
void MatrixAddition::displaySum(){

	int count = 1;
	cout << "\n-- Result --\nSum of A and B:" << endl;

	//getting the matrix to print in a 2D format
	//using a counter variable to count the end of the row and reset
	//even number of rows
	if (rows % 2 == 0) {

		for (int i = 0; i < sumMatrices.size(); i++) {

			if (count % rows == 0) {

				cout << setw(6);
				cout << sumMatrices[i] << endl;
				count == 0;
			}

			else {

				cout << setw(6);
				cout << sumMatrices[i];
			}

			count++;
		}
	}

	//odd number of rows
	if (rows % 2 != 0) {

		for (int i = 0; i < sumMatrices.size(); i++) {

			if (count % rows == 0) {

				cout << setw(6);
				cout << sumMatrices[i] << endl;
			}

			else{

				cout << setw(6);
				cout << sumMatrices[i];
			}				

			count++;
		}
	}

	cout << "______________________________________________________________" << endl;
}