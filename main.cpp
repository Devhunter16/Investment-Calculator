#include <iostream>
#include <iomanip>

using namespace std;

#include "InvestmentCalculator.h"

/**
* This program will intake user input and output investment calculations based on that input.
* 
* Author: Devin Hunter
* 10/2/21
*/

int main() {

	InvestmentCalculator userCalc;

	// Exception handling for invalid user inputs
	try {
		userCalc.runProgram();
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		cout << endl;
		userCalc.runProgram();
		
	}

	return 0;
}