#include "calculate.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	string input="";
	Calculator* Calc = new Calculator;
	double res=0;
	bool ContinueCalculation = true;
	int answer = 0;
	cout << "��������� ��������� �������� ���������� ��������� �� �������� �������� ������." << endl;
	while (ContinueCalculation) {

		cout << "������� ���������: ";
		cin >> input;
		cout << endl;

		res = Calc->Calculate(input);
		cout << "���������: " << res << endl;
		
		cout << "������ ����� ���������?(0 - ���| 1 - ��): ";
		cin >> answer;
		cout << endl;
		if (answer == 0)
		{
			ContinueCalculation = false;
		}
	}

	return 0;
}