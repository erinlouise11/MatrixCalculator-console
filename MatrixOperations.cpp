// MatrixOperations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Erin Murphy 

#include <iostream>
#include <vector>
#include "MatrixAddition.h"
#include "MatrixSubtraction.h"
#include "MatrixMultiplication.h"

int main() {
	 
	bool acceptDimensions;
	int run = 1, option, rowsA, colsA, rowsB, colsB, element;
	
	//run until user wants to quit
	while (run == 1) {

		//displaying header and taking in the operation type as an integer
		cout << "----- Matrix Calculator -----" << endl << endl;
		cout << "Select operation: \n1. Addition \n2. Difference \n3. Multiplication \n\n";

		cout << "Option: ";
		cin >> option;

		//addition option
		if (option == 1) {

			//creating addition object 
			MatrixAddition addition;

			//addition requires matrices to be of equal dimensions, input rows and set columns = rows
			cout << "\n--- Matrix Addition --- \nEnter MxM dimension:";
			cin >> rowsA;
			addition.setRows(rowsA);
			colsA = rowsA;

			//creating matrix A, adding in each element from the user
			cout << "\nEnter elements for matrix A (press enter after each element):" << endl;
			for (int i = 0; i < rowsA; i++) {

				for (int j = 0; j < colsA; j++) {

					cin >> element;
					addition.createMatrixA(element);					
				}
			}

			//creating matrix B, adding in each elemnt from the user
			cout << "\nEnter elements for matrix B (press enter after each element):" << endl;
			for (int i = 0; i < rowsA; i++) {

				for (int j = 0; j < colsA; j++) {

					cin >> element;
					addition.createMatrixB(element);					
				}
			}

			cout << endl;
			
			//calling function to add the matrices 
			addition.addMatrices();
			//addition.printMatrix();

			//calling function to display the sum of the matrices
			addition.displaySum();
		}

		//subtraction option
		if (option == 2) {

			//creating a subtraction object
			MatrixSubtraction subtraction;

			//subtraction requires matrices to be of equal dimensions, input rows from user and set columns = rows
			cout << "\n--- Matrix Subtraction --- \nEnter MxM dimension:";
			cin >> rowsA;
			subtraction.setRows(rowsA);
			colsA = rowsA;

			//creating matrix A 
			cout << "\nEnter elements for matrix A (press enter after each element):" << endl;
			for (int i = 0; i < rowsA; i++) {

				for (int j = 0; j < colsA; j++) {

					cin >> element;
					subtraction.createMatrixA(element);
				}
			}

			//creating matrix B
			cout << "\nEnter elements for matrix B (press enter after each element):" << endl;
			for (int i = 0; i < rowsA; i++) {

				for (int j = 0; j < colsA; j++) {

					cin >> element;
					subtraction.createMatrixB(element);
				}
			}

			cout << endl;

			//calling function to subtract the matrices
			subtraction.subtractMatrices();

			//calling the function to display the difference
			subtraction.displayDifference();
		}

		//multiplication option
		if (option == 3) {

			//creating a multiplication object
			MatrixMultiplication multiplication;

			//getting the dimensions
			cout << "\n--- Matrix Multiplication --- \nEnter MxN dimension for matrix A\nRows:";
			cin >> rowsA;
			cout << "Columns:";
			cin >> colsA;

			cout << "\nEnter MxN dimension for matrix B\nRows:";
			cin >> rowsB;
			cout << "Columns:";
			cin >> colsB;

			multiplication.setARows(rowsA);
			multiplication.setACols(colsA);
			multiplication.setBRows(rowsB);
			multiplication.setBCols(colsB);
			
			//columns of matrix Aand rows of matrix B should be equal in order to multiply matrices
			//this error checking is done in the multiplication class
			acceptDimensions = multiplication.prodDimension();

			//after error checking, if not accepted then message shown and user must re enter the dimensions
			while (!acceptDimensions) {

				//if the user wants to go back to the main menu or quit
				cout << "\nCannot multiply matrices. A cols must equal B rows!" << endl;
				cout << "Try again (2) | Back to menu (1) | Exit (0): ";
				cin >> run;				

				//continue and start over again getting dimensions
				if (run == 2) {

					cout << "\nTry again!\nEnter MxN dimension for matrix A\nRows:";
					cin >> rowsA;
					cout << "Columns:";
					cin >> colsA;

					cout << "\nEnter MxN dimension for matrix B\nRows:";
					cin >> rowsB;
					cout << "Columns:";
					cin >> colsB;

					multiplication.setARows(rowsA);
					multiplication.setACols(colsA);
					multiplication.setBRows(rowsB);
					multiplication.setBCols(colsB);

					acceptDimensions = multiplication.prodDimension();
				}						
			}

			//getting the elements for matrix A
			cout << "\nEnter elements for matrix A (press enter after each element):" << endl;

			for (int i = 0; i < rowsA; i++) {

				vector<int> temp;

				for (int j = 0; j < colsA; j++) {

					cin >> element;
					temp.push_back(element);					
				}

				multiplication.createMatrixA(temp);
			}			

			//getting the elements for matrix B
			cout << "\nEnter elements for matrix B (press enter after each element):" << endl;
			for (int i = 0; i < rowsB; i++) {

				vector<int> temp;

				for (int j = 0; j < colsB; j++) {

					cin >> element;
					temp.push_back(element);
				}

				multiplication.createMatrixB(temp);
			}

			//multiplication.printMatrix();

			//calling function to multiply the matrices
			multiplication.multiplyMatrices();

			//calling function to display the product matrix
			multiplication.displayProduct();
		}	

		//if the user wants to go back to the main menu or quit
		cout << "\n\nBack to menu (1) | Exit (0): ";
		cin >> run;	
		cout << endl << endl;
	}	
}