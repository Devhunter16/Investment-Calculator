#include <iostream> // iostream makes is so I can get inputs and ouputs from the user.
#include <iomanip>  // iomanip makes it so I can use setprecision().

using namespace std;

#include "InvestmentCalculator.h"

// This function displays the menu and gets user input.
void InvestmentCalculator::runProgram() {
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> m_initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> m_monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> m_annualInterest;
	cout << "Number of years: ";
	cin >> m_years;
	m_months = m_years * 12;
	cout << endl;

	system("Pause"); // This outputs "press any key to continue..."
	cout << endl;
	
	if (m_initialInvestment < 0) {
		// Throws an error if initial investment amount is negative
		throw runtime_error("One or more of your inputs was a negative number. Please try again.");
	}

	if (m_annualInterest < 0) {
		// Throws an error if annual interest amount is negative
		throw runtime_error("One or more of your inputs was a negative number. Please try again.");
	}

	if (m_years < 0) {
		// Throws an error if number of years is negative
		throw runtime_error("One or more of your inputs was a negative number. Please try again.");
	}

	if (m_monthlyDeposit == 0) {
		m_outputDisplayWithoutMonthly();
	}
	else if (m_monthlyDeposit > 0) {
		m_outputDisplayWithMonthly();
	}
	else {
		// Throws an error if monthly deposit is negative
		throw runtime_error("One or more of your inputs was a negative number. Please try again.");
	}
}

// This function displays output if the user enters no monthly deposits.
void InvestmentCalculator::m_outputDisplayWithoutMonthly() {
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;
	m_calculateOutputWithoutMonthly();
}

// This function calculates the yearly interest and year-end interest based on user input if the user entered no monthly deposits.
void InvestmentCalculator::m_calculateOutputWithoutMonthly() {
	m_totalAmount = m_initialInvestment;

	//Calculates the yearly interest
	for (int i = 0; i < m_years; i++) {
	    m_interestAmount = ((m_totalAmount) * (m_annualInterest / 100));

		//Calculates the year end total
		m_totalAmount = m_totalAmount + m_interestAmount;

		//Shows the decimal amount as a dollar amount correctly 
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t$" << m_interestAmount << endl;
	}

	// Asks the user if they'd like to enter different values and restarts.
	cout << endl;
	cout << "Would you like to enter different values?" << endl;
	system("Pause");
	cout << endl;
	runProgram();
}

// This function displays output if the user enters monthly deposits.
void InvestmentCalculator::m_outputDisplayWithMonthly() {
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;
	m_calculateOutputWithMonthly();
}

// This function calculates the monthly interest and the month-end total based on user inputs if the user entered monthly deposits.
void InvestmentCalculator::m_calculateOutputWithMonthly() {
	m_totalAmount = m_initialInvestment;

	//Calculates the yearly interest
	for (int i = 0; i < m_years; i++) {

		m_yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			//Calculates the monthly interest amount
			m_interestAmount = (((m_totalAmount + m_monthlyDeposit) * (m_annualInterest / 100)) / 12);

			//Calculates the month-end interest
			m_yearlyTotalInterest = m_yearlyTotalInterest + m_interestAmount;

			//Calculates the month-end total
			m_totalAmount = m_totalAmount + m_monthlyDeposit + m_interestAmount;
		}

		//Shows the decimal amount as a dollar amount correctly
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << m_totalAmount << "\t\t\t$" << m_yearlyTotalInterest << endl;
	}

	// Asks the user if they'd like to enter different values and restarts.
	cout << endl;
	cout << "Would you like to enter different values?" << endl;
	system("Pause");
	cout << endl;
	runProgram();
}
