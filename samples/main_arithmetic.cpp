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
	bool ContinueСurrentCalculation = true;
	bool ExpressionNotCorrectly = true;

	int answer = 0;
	cout << "Программа реализует алгоритм вычисления выражения по обратной польской записи." << endl;

	while (ContinueCalculation) {
		res = 0;
		ContinueСurrentCalculation = true;
		ExpressionNotCorrectly = true;

		while (ExpressionNotCorrectly) {
			cout << "Введите выражение: ";
			cin >> input;
			cout << endl;
			try {
				Parser p;
				Lexema* lexems_input = p.Parse(input);
				Corrector c;
				Stack<Error>* errors;
				errors = c.CheckExpression(lexems_input);
				ExpressionNotCorrectly = false;
				while (!errors->IsEmpty()) {
					Error err = errors->Put();
					cout << err.GetText() << err.GetPosition() << endl;
					ExpressionNotCorrectly = true;
				}
				if (ExpressionNotCorrectly)
				{
					throw "Ошибка в выражении";
				}
				
			}
			catch (...) {
				cout << "Введите выражение повторно!" << endl;
			}
		}
		
		while (ContinueСurrentCalculation) {
			res = Calc->Calculate(input);
			cout << "Результат: " << res << endl;
			cout << "Повторить с новыми переменными?(0 - нет| 1 - да): ";
			cin >> answer;
			cout << endl;
			if (answer == 0) {
				ContinueСurrentCalculation = false;
			}
		}
		cout << "Ввести новое выражение?(0 - нет| 1 - да): ";
		cin >> answer;
		cout << endl;
		if (answer == 0)
		{
			ContinueCalculation = false;
		}
	}

	return 0;
}