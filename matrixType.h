#ifndef matrixTypeH
#define matrixTypeH

#include <iostream>         // For showing information and getting information from user
#include <string>           // For stoi() and getline()
using namespace std;        // Setting namespace to STD::
int const STALL_INT = -999; // CONST that is used to declare a space in matrix that has not been set yet 



class matrixType {
private:
	int columns;            // Holds the amount of columns this matrix has
	int rows;               // Holds the amount of rows this matrix has
	int** matrix;           // A int pointer to an array that int pointers to arrays
	string identifier;      // The name of this matrix, used when displaying messages that need to identify the working matrix
	
	matrixType* results;    // A matrix that this object can make when doing operations to send back information that is not temporary but rather stay alive while object is alive


	

	// Helper Functions
	int multArrays(int* arr1, int* arr2, int size);  // Multiplies arrays and returns the sum (using matrix multiplcation logic)
	bool validInput(string input, bool allowNeg);    // Checks for valid input
	

public:
	// Constructors and Destructors: --------------------------------------------------------------------------------------------------------------------------------
	matrixType(string i) { columns = rows = 0; matrix = nullptr; results = nullptr; identifier = i; }  // Constructor used everywhere
	~matrixType();                                                                                     // Destructor is to prevent memory leak since we are using dynamic arrays
	
	
	// Set Functions:  ----------------------------------------------------------------------------------------------------------------------------------------------
	void setMatrix();                                                                                  // Sets up the matrix using input from user
	void resetResults(int col, int nRow, string iden);												   // Resets/Initializes the result matrix to do a operation 


	// Get Functions (returns corresponding values) -----------------------------------------------------------------------------------------------------------------
	int getColumns() const { return columns; }                                                         // Returns Cols
	int getRows() const { return rows; }                                                               // Returns Rows
	string getIdent() const { return identifier; }                                                     // Returns Identifier


	// Input/Output Overload Functions: -----------------------------------------------------------------------------------------------------------------------------
	friend ostream& operator<<(ostream& outputStream, matrixType& currMatrix);                         // To print out a matrix, using "cout << "
	friend istream& operator>>(istream& inputStream, matrixType& currMatrix);                          // To input a matrix, using "cin >>"


	//Operator Overloading Functions
	matrixType& operator+(matrixType& right);                                                          // To add 2 matrixs, using "m1 + m2"
	matrixType& operator-(matrixType& right);                                                          // To sub 2 matrixs, using "m1 - m2"
	matrixType& operator*(matrixType& right);                                                          // To Mult 2 matrixs, using "m1 * m2"
	

	// Extra Friends: -----------------------------------------------------------------------------------------------------------------------------------------------
	friend void drawHelper(matrixType& currMatrix, int col, int row);                                  // Function that prints out the target insetion when inseting data into matrix

};

/*
========================================================|
// V I S U A L   A I D: 								|
// This is how the array looks like inside of the matrix|
========================================================| 
-> Each Column is an index in MATRIX array
-> In each column there is another array that holds the value for that row
 
  MATRIX = [ C1, C2, C3 ]
  C1 = [X,Y,Z]
  C2 = [A,B,C]
  C3 = [J,L,M]
       C1     C2    C3    <--- Columns
Row 1  X      A     J
Row 2  Y      B     L
Row 3  Z      C     M
  ^
 Rows

*/



#endif 