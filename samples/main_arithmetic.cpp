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
	bool Continue—urrentCalculation = true;
	bool ExpressionNotCorrectly = true;
	int answer = 0;
	cout << "œÓ„‡ÏÏ‡ Â‡ÎËÁÛÂÚ ‡Î„ÓËÚÏ ‚˚˜ËÒÎÂÌËˇ ‚˚‡ÊÂÌËˇ ÔÓ Ó·‡ÚÌÓÈ ÔÓÎ¸ÒÍÓÈ Á‡ÔËÒË." << endl;
	while (ContinueCalculation) {
		while (Continue—urrentCalculation) {
			while (ExpressionNotCorrectly) {
				cout << "¬‚Â‰ËÚÂ ‚˚‡ÊÂÌËÂ: ";
				cin >> input;
				cout << endl;
				try
				{
					res = Calc->Calculate(input);
					ExpressionNotCorrectly = false;
				}
				catch (...)
				{
					cout << "¬‚Â‰ËÚÂ ‚˚‡ÊÂÌËÂ ÔÓ‚ÚÓÌÓ!"<<endl;
				}
			}
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