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
	bool Continue�urrentCalculation = true;
	bool ExpressionNotCorrectly = true;
	int answer = 0;
	cout << "��������� ��������� �������� ���������� ��������� �� �������� �������� ������." << endl;
	while (ContinueCalculation) {
		while (Continue�urrentCalculation) {
			while (ExpressionNotCorrectly) {
				cout << "������� ���������: ";
				cin >> input;
				cout << endl;
				try
				{
					res = Calc->Calculate(input);
					ExpressionNotCorrectly = false;
				}
				catch (...)
				{
					cout << "������� ��������� ��������!"<<endl;
				}
			}
			cout << "���������: " << res << endl;
			cout << "��������� � ������ �����������?(0 - ���| 1 - ��): ";
			cin >> answer;
			cout << endl;
			if (answer == 0) {
				Continue�urrentCalculation = false;
			}
		}
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