//Team#: 8
//Team Member - 1 : Emanuel Sanchez Member’s Contribution(in%) 50
//Team Member - 2 : Dion Bobino Member’s Contribution(in%) 50


#include "matrixType.h";  // Including the H File to make the objects
using namespace std;      // Changing namespace to STD::


int main() {
	matrixType m1("1"), m2("2");                 // Creating the two objs with names 1 and 2
	cin >> m1 >> m2;                                               // Overloaded >> operator

	

	cout << "\n----------- Matrix Inputted -------------" << endl << endl;
	cout << m1 << m2;                                              // Overloaded << operator


	cout << "-------------   RESULTS   ---------------" << endl;

	cout << (m1 + m2);                                             // Overload + operator
	cout << (m1 - m2);											   // Overload - operator
	cout << (m1 * m2);											   // Overload * operator

	string tempString;
	cout << "Push enter to continue..." << endl;
	cin >> tempString;
	
	return 0;
}


