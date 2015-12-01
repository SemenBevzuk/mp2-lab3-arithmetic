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
	cout << "Программа реализует алгоритм вычисления выражения по обратной польской записи." << endl;
	while (ContinueCalculation) {

		cout << "Введите выражение: ";
		cin >> input;
		cout << endl;

		res = Calc->Calculate(input);
		cout << "Результат: " << res << endl;
		
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