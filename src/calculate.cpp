#include "calculate.h"

double Calculator::Calculate(string input)
{
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Lexema* lexema = lexems_input;
	/*while (lexema->GetType() != Type_Lexems::terminal)
	{
		cout << lexema->GetValue() << ",";
		lexema++;
	}
	cout << endl;*/

	Corrector c;
	Stack<Error>* errors;
	Stack<Lexema>* PolishNotationStack;
	double res;

	errors = c.CheckExpression(lexems_input);
	while (!errors->IsEmpty()) {
		Error err = errors->Put();
		cout << err.GetText() << err.GetPosition() << endl;
		throw "������ � ���������";
	}

	Aggregate aggregate;
	aggregate.FillVar(lexems_input);

	Switch s;
	PolishNotationStack = s.build_notation(lexems_input);
	
	ReversePolishNotation r;
	res = r.�alculate(PolishNotationStack);

	return res;
}