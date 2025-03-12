#include "matrixType.h"   // Including .h file into this CPP as well
#include <iomanip>        // Used to make a nicer UI Experience 
using namespace std;




//=================================================,.
// Helper Functions:                                |:-------------------------------------------------------------------------------------------------//
//=================================================''																								   //
																																					   //
void cls() { // Creates a space for a nicer UI experience																							   //
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";																			   //
}																																					   //
																																					   //
bool matrixType::validInput(string input, bool allowNeg) {     // Checks that every char in string is a number										   //
	if (input.length() == 0)                       //   - Bool: decides if negatives are allowed in number											   //
		return false;																																   //
	for (int i = 0; i < input.length(); i++) {																										   //
		if (i == 0 && input[i] == '-' && allowNeg) // If neg allowed then skip first -																   //
			continue;																																   //
		if (!isdigit(input[i]))                    // If current char is not a number, returns false												   //
			return false;																															   //
	}																																				   //
	return true;                                   // If passed all test, input is valid, return true												   //
}																																					   //
																																					   //
int matrixType::multArrays(int* arr1, int* arr2, int size) {   // SUMMATION_i=<0>_TO_i=<size-1>:(arr1[i]*arr2[i])									   //
	int total = 0;																																	   //
																																					   //
	for (int i = 0; i < size; i++) {               // For every index, multiply the corresponding location of both arr. and add to running total	   //
		total += (arr1[i] * arr2[i]);																												   //
	}																																				   //
																																					   //
	return total;                                  // Return the full summation																		   //
}																																					   //
																																					   //
																																					   //
																																					   //
																																					   //
//=================================================,.																								   //
// Set Functions:                                   |:-------------------------------------------------------------------------------------------------//
//=================================================''                                                                                                  //
																																					   //
void matrixType::setMatrix() {                            // Sets up the matrix through user input													   //
	string tempString = "";																															   //
	for (int i = 0; i < columns; i++) {                   // For everycolumn do the below:															   //
		for (int j = 0; j < rows; j++) {                  // For every row do the below: (going down the columns then back up to next column)		   //
			do {																																	   //
				cls();                                    // Clearing screen																		   //
				if (tempString == "errorMessage")         // Shows error message if last attempt was an error										   //
					cout << "> ERROR: Please enter a valid number.\n" << endl;																		   //
				drawHelper(*this, i, j);                  // Sends in this matrix and the current col and row that we are setting up				   //
				cout << "Enter information for Matrix " << identifier << ":" << endl; // Using identifier to make dynamic							   //
				cout << "-----------------------------------------" << endl;																		   //
				cout << "  Enter the items for the COLUMN " << i+1 << ": " << endl;   // Showing user the current col								   //
				cout << "    Row " << j + 1 << " : ";                                 // Showing user the current row								   //
																																					   //
				getline(cin, tempString);                 // Grabbing the users input																   //------//
				if (!validInput(tempString, true)) {      // Checking if the input has anything that is not a digit, but allowing negative numbers too         //
					tempString = "errorMessage";          //    -> If the input is invalid, setting the tempstring so that next iteration, error message shows //
				}                                         //    -> Tempstring now being letters also does not pass the while loop and forces another iteration //
			} while (tempString == "errorMessage");       // If input was invalid, do another iteration                                                        //
																																					   //------//
			matrix[i][j] = stoi(tempString);              // After everything, convert tempstring to int and set that matrix location				   //
		}																																			   //
	}																																				   //
	cls();                                                // Clearing screen after everything for next step											   //
}																																					   //
																																					   //
 void matrixType::resetResults(int col, int nRow, string iden) { // Reset results matrix pointer to whatever it needs to be							   //
	if (results == nullptr) { 									 // Enters if this is the first time this class has used the results matrix			   //
		results = new matrixType(iden);				 // Makes a new matrix to save taht will be used to return results					   //
	}															 																					   //
	else {														 // Enters if it already has a matrix made for it									   //
		for (int i = 0; i < results->columns; i++) {			 // Deletes everything inside current matrix										   //
			delete[] results->matrix[i];						 																					   //
		}														 																					   //
		delete[] results->matrix;								 																					   //
		results->matrix = nullptr;								 // Resets to nullptr, not really important because we will change right after this	   //
	}															 																					   //
																 																					   //
	results->identifier = iden;									 // This sets the identifier which will be "Addition/Subtraction/Multiplication"	   //
	results->columns = col;										 // |Making everything else match up to the paramaters 								   //
	results->rows = nRow;										 // |																				   //
	results->matrix = new int* [col];							 // Creating the new matrix columns													   //
																 																					   //
	for (int i = 0; i < col; i++){								 // Creating the new matrix rows inside the columns									   //
		results->matrix[i] = new int[nRow];						 																					   //
	}															 																					   //
																 																					   //
	for (int i = 0; i < col; i++){								 // Setting everything inside this matrix to be STALL_INT							   //
		for (int j = 0; j < nRow; j++){							 // -> This will be returned immediatly in the operator functions so that it will	   //
			results->matrix[i][j] = STALL_INT;					 //    recognize that it failed the testing stage and operation is not possible		   //
		}														 																					   //
	}															 																					   //
}																 																					   //
																																					   //
																																					   //
																																					   //
//=================================================,.																								   //
// Input/Output Functions:                          |:-------------------------------------------------------------------------------------------------//
//=================================================''																								   //
																																					   //
void drawHelper(matrixType& currMatrix, int col, int row) {// Draws the helper that is shown when inputting matrix									   //
	cout << "     \t\t";                                   // Sets the spacing before the column titles												   //
	for (int i = 0; i < currMatrix.columns; i++) {          // For every column, space out and put c<number>										   //
		cout << "C." << i + 1 << " ";																												   //
	}																																				   //
	cout << endl;                                          // Needed to start next line																   //
																																					   //
	for (int i = 0; i < currMatrix.rows; i++) {            // For every row do the below:															   //
		cout << "Row " << i + 1 << ":\t\t";                // Type the row number and add spacing													   //
		for (int j = 0; j < currMatrix.columns; j++) {     // For every column do the below:														   //
			if (j == col && i == row)                      // If this is the current col and row specified, draw the X								   //
				cout << "[X] ";																														   //
			else if (currMatrix.matrix[j][i] == STALL_INT) // If this is a place that has not been set up, draw the [ ]								   //
				cout << "[ ] ";																														   //
			else {                                         // If it is a number that already is set up, type that number							   //
				cout << setw(3) << right << currMatrix.matrix[j][i] << " ";																			   //
			}																																		   //
		}																																			   //
		cout << endl;                                      // Go to the next line to prepare for next row											   //
	}																																				   //
}																																					   //
																																					   //
ostream& operator<<(ostream& outputStream, matrixType& currMatrix) { // Overloading the << operator to display the matrix	
	
	if (currMatrix.matrix[0][0] == STALL_INT) {		                       // Catches when sent from operations and the size did not match up		   //																					   //
		outputStream << "> ERROR: " << currMatrix.identifier << " not possible because of size mismatch." << endl;									   //
		return outputStream;															 														       //
	}																																				   //
	outputStream << "Matrix " << currMatrix.identifier << ":\n";																					   //
	for (int i = 0; i < currMatrix.rows; i++) {                            // For every row do the below:											   //
		outputStream << "Row " << i + 1 << ":\t\t";                                // Print out the row number and spacing					     	   //
		for (int j = 0; j < currMatrix.columns; j++) {                     // For every col do the below:											   //
			outputStream << setw(4) << right << currMatrix.matrix[j][i] << " ";    // Printing out every item in that "row" of columns				   //
		}																																			   //
		outputStream << endl;                                                      // Going to next line to print out next row						   //
	}																																				   //
	outputStream << endl;																															   //
	return outputStream;                                                   // Returning stream so we can use "cout << m1 << m2						   //
	
}																																					   //
																																					   //
istream& operator>>(istream& inputStream, matrixType& currMatrix) {        // Overloading the >> operator to input a new matrix, including a new size  //
	string tempString = "";																															   //
																																					   //
	do {																																			   //
		cls();                                                             // Clearing the screen 													   //
		if (tempString == "errorMessage")                                  // If previous iteration was a invalid input, show error message			   //
			cout << "> ERROR: Please enter a valid number.\n" << endl;     																			   //
		cout << "Entering information for Matrix " << currMatrix.identifier << ":" << endl;															   //
		cout << "Enter the amount of columns: ";																									   //-------------------------------//
		getline(inputStream, tempString);                                          // Grabbing input from user																					//
		if (!currMatrix.validInput(tempString, false)) {                   // Testing if this input is valid for conversion, negatives are NOT allowed (this is the size)				//
			tempString = "errorMessage";                                   // Setting trigger for error message and to enter another iteration											//
		}																																												//
		else if(stoi(tempString) == 0){                                    // Conversion was possible, but checking if entered number is 0 (could not be less bc neg. were not allowed)	//
			tempString = "errorMessage";                                   // Setting trigger for error message and to enter another iteration											//
		}																																			   //-------------------------------//
	} while (tempString == "errorMessage");                                // Re-iterates if there was a invalid input								   //
	currMatrix.columns = stoi(tempString);                                 // Converts and set the columns											   //
																																					   //
																																					   //
	do {																																			   //
		cls();                                                                              //														   //
		if (tempString == "errorMessage")                                                   //														   //
			cout << "> ERROR: Please enter a valid number.\n" << endl;                      // 														   //
		cout << "Entering information for Matrix " << currMatrix.identifier << ":" << endl; //														   //
		cout << "Enter the amount of columns: " << currMatrix.columns << endl;              //														   //
		cout << "Enter the amount of rows   : ";                                            //														   //
		getline(inputStream, tempString);                                                           //														   //
		if (!currMatrix.validInput(tempString, false)) {                                    //  This block holds exactly the same thing as above	   //
			tempString = "errorMessage";                                                    //  except that the user is inputting information for the  //
		}																					//  rows instead of columns								   //
		else if(stoi(tempString) == 0){														//														   //
			tempString = "errorMessage";													//														   //
		}																					//														   //
	} while (!currMatrix.validInput(tempString, false));									//														   //
	currMatrix.rows = stoi(tempString);														//														   //
																																					   //
																																					   //
	currMatrix.matrix = new int* [currMatrix.columns];         // Setting up the matrix with <columns> amount of pointers of int 					   //
	for (int i = 0; i < currMatrix.columns; i++) {             // Setting up for each pointer in matrix to hold a dynamic array of int's			   //
		currMatrix.matrix[i] = new int[currMatrix.rows];																							   //
	}																																				   //
																																					   //
	for (int i = 0; i < currMatrix.columns; i++){              // Setting up each item in matrix to be equal to STALL_INT							   //
		for (int m = 0; m < currMatrix.rows; m++){             // this will be the trigger for the drawHelper function								   //
			currMatrix.matrix[i][m] = STALL_INT;																									   //
		}																																			   //
	}																																				   //
																																					   //
	currMatrix.setMatrix();                                    // Sending to setMatrix() to finish setting up
	return inputStream;                                        // Sending back the stream so that it can be cin >> m1 >> m2							   //
}																																					   //
																																					   //
																																					   //
																																					   //
																																					   //
																																					   //
																																					   //
//=================================================,.																								   //
// Operator Overload Functions:                     |:------------------------------------------------------------------------------------------------ //
//=================================================''																								   //
																																					   //
																																					   //
																																					   //
matrixType& matrixType::operator+(matrixType& right) {                  // Overloading the + operator												   //	   
	resetResults(columns, rows, "Addition");                            // Using this function to set up the results matrix and the name of operation  //
	int tempInt;                                                        // Made so code would be easier to read, it holds the value that will be set   //
	if ((columns != right.columns) || (rows != right.rows)) {           // Checking if addition is valid: both rows and cols have to equal to each other/ 	 
		return *results;                                                // Sending back an empty matrix with STALL_INT that will be caught if printed  //
	}																																				   //
																									                                                   //                                                                                      
	for (int i = 0; i < columns; i++){                                  // For every item (every item in row in every column)						   //
		for (int j = 0; j < rows; j++){																												   //
			tempInt = matrix[i][j] + right.matrix[i][j];                // Adding the two same positions in both matrix and holding sum in tempInt 	   //
			results->matrix[i][j] =  tempInt;                           // Setting this value into the position in the results matrix 				   //
		}																																			   //
	}																																				   //
	return *results;                                                    // Sending back the finished matrix											   //
}																																					   //
																																					   //
//																																					   //
																																				       //
matrixType& matrixType::operator-(matrixType& right) {                  // Overloading the - operator												   //	  
	resetResults(columns, rows, "Subtraction");                         // Using this function to set up the results matrix and the name of operation  //
	int tempInt;                                                        // Will hold the value that will be set in the new matrix					   //
	if ((columns != right.columns) || (rows != right.rows)) {           // Checking if addition valid: both rows and cols have to equal to each other  //  
		return *results;												// Returning the empty matrix again with the STALL_INT						   //
	}																																				   //
	for (int i = 0; i < columns; i++) {                                 // For every find item in this new matrix									   //
		for (int j = 0; j < rows; j++) {																											   //
			tempInt = matrix[i][j] - right.matrix[i][j];                // Subtract the two positions and hold the difference in tempInt			   //
			results->matrix[i][j] = tempInt;                            // Setting this value into the position in the results matrix                  //
		}																																			   //
	}																																				   //
	return *results;													// Returning the matrix 													   //
}																																					   //
																																					   //
																																			     	   //
matrixType& matrixType::operator*(matrixType& right) {																								   //---------------//
	resetResults(right.columns, this->rows, "Multiplication");                        // Using function to set values in result matrix and setting opration name        //
	int tempInt;                                                                      // Will hold the value that will be set into the new matrix					    //
																																										//
	if (columns != right.rows) {                                                      // Checking if * is valid: columns of left must equal rows of right			    //	
		return *results;                                                              // Sending back an empty matrix with STALL_INT that will be caught 			    //
	}																																									//	
																																										//	
																																										//	
	int* thisRowArray = new int[this->columns];                                       // A dynamic array because size is not known until runtime						//	
																																										//	
	for (int i = 0; i < right.columns; i++) {                                         // For every row in the left:														//	
		for (int j = 0; j < this->rows; j++) {                                        // For every column in the right:													//	
			for (int m = 0; m < this->columns; m++) {                                 // For every column in the left:													//	
				thisRowArray[m] = this->matrix[m][j];                                 // Set up the array made to be the "row" of the columns of the left matrix		//	
			}																																							//	
			tempInt = multArrays(thisRowArray, right.matrix[i], this->columns);		  // Send in the copy of the "row of the columns" of the left and the right columns	//																															 //
			results->matrix[i][j] = tempInt;                                          // Setting that value into the result matrix at the position of [j][i]			//
		}                																															  //----------------//
	}																																				  //
	delete[] thisRowArray;	                                                          // Once finished, delete this array to prevent memory leak	  //
	return *results;                                                                  // Sending back the matrix								      //
}																																					  //
																																					  //
																																					  //																																				  //
//=================================================,.																								  //
// Constructors/Destructor                          |:------------------------------------------------------------------------------------------------//
//=================================================''																								  //
																																					  //
matrixType::~matrixType() {                             // Distructor because we allocated dynamic arrays						            		  //
	for (int i = 0; i < columns; i++) {                 // For every column in matrix											            		  //
		delete[] matrix[i];                             // Delete the array saved in the index of matrix						            		  //
	}									               																			            	      //
	delete[] matrix;                                    // After every index is free, free this matrix as well					            		  //
	matrix = nullptr;																																  //
																																					  //
																																					  //
	if (results != nullptr) {							// If the results in this current object has been used, it must be deleted				      //														
		for (int i = 0; i < results->columns; i++) {	// Going through every column in this matrix and deleting their rows						  //																
			delete[] results->matrix[i];																											  // 
		}																																			  // 
		delete[] results->matrix;						// Deleteing now the columns in the matrix 													  // 										
		results->matrix = nullptr;						// Setting back to nullptr, not really necessary but good practice						      //															
	}																																				  //
}																																					  //
																																					  //
//----------------------------------------------------------------------------------------------------------------------------------------------------//