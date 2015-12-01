#include "calculate.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string input="";
	Calculator* Calc = new Calculator;
	double res=0;
	bool ContinueCalculation = true;
	bool Continue�urrentCalculation = true;
	bool ExpressionNotCorrectly = true;
	int answer = 0;
	cout << "��������� ��������� �������� ���������� ��������� �� �������� �������� ������." << endl;
	while (ContinueCalculation) {
		ExpressionNotCorrectly = true;
		while (ExpressionNotCorrectly) {
			cout << "������� ���������: ";
			cin >> input;
			cout << endl;
			try {
				Parser p;
				Lexema* lexems_input = p.Parse(input);
				Corrector c;
				Stack<Error>* errors;
				errors = c.CheckExpression(lexems_input);
				while (!errors->IsEmpty()) {
					Error err = errors->Put();
					cout << err.GetText() << err.GetPosition() << endl;
					throw "������ � ���������";
				}
				ExpressionNotCorrectly = false;
			}
			catch (...) {
				cout << "������� ��������� ��������!" << endl;
			}
		}
		while (Continue�urrentCalculation) {
			res = Calc->Calculate(input);
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