#pragma once

// Here I intantiate my class and all public and private members.
class InvestmentCalculator {             
public:
	void runProgram();
private:
	void m_calculateOutputWithoutMonthly();
	void m_calculateOutputWithMonthly();
	void m_outputDisplayWithoutMonthly();
	void m_outputDisplayWithMonthly();
	double m_totalAmount;
	double m_interestAmount;
	double m_yearlyTotalInterest;
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	double m_months;
	double m_years;
};