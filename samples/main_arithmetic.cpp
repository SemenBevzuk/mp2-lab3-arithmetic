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
	bool Continue—urrentCalculation = true;
	bool ExpressionNotCorrectly = true;
	int answer = 0;
	cout << "œÓ„‡ÏÏ‡ Â‡ÎËÁÛÂÚ ‡Î„ÓËÚÏ ‚˚˜ËÒÎÂÌËˇ ‚˚‡ÊÂÌËˇ ÔÓ Ó·‡ÚÌÓÈ ÔÓÎ¸ÒÍÓÈ Á‡ÔËÒË." << endl;
	while (ContinueCalculation) {
		ExpressionNotCorrectly = true;
		while (ExpressionNotCorrectly) {
			cout << "¬‚Â‰ËÚÂ ‚˚‡ÊÂÌËÂ: ";
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
					throw "Œ¯Ë·Í‡ ‚ ‚˚‡ÊÂÌËË";
				}
				ExpressionNotCorrectly = false;
			}
			catch (...) {
				cout << "¬‚Â‰ËÚÂ ‚˚‡ÊÂÌËÂ ÔÓ‚ÚÓÌÓ!" << endl;
			}
		}
		while (Continue—urrentCalculation) {
			res = Calc->Calculate(input);
			cout << "–ÂÁÛÎ¸Ú‡Ú: " << res << endl;
			cout << "œÓ‚ÚÓËÚ¸ Ò ÌÓ‚˚ÏË ÔÂÂÏÂÌÌ˚ÏË?(0 - ÌÂÚ| 1 - ‰‡): ";
			cin >> answer;
			cout << endl;
			if (answer == 0) {
				Continue—urrentCalculation = false;
			}
		}
		cout << "¬‚ÂÒÚË ÌÓ‚ÓÂ ‚˚‡ÊÂÌËÂ?(0 - ÌÂÚ| 1 - ‰‡): ";
		cin >> answer;
		cout << endl;
		if (answer == 0)
		{
			ContinueCalculation = false;
		}
	}

	return 0;
}