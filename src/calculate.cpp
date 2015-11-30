#include "calculate.h"

double Calculator::Calculate(string input)
{
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Corrector c;
	Stack<Error>* errors;
	Stack<Lexema>* PolishNotationStack;
	Stack<Lexema>* GoodPolishNotationStack;
	double res;

	errors = c.CheckExpression(lexems_input);
	while (!errors->IsEmpty()) {
		Error err = errors->Put();
		string str = err.GetText();
		cout << str << err.GetPosition() << endl;
	}

	Switch s;
	PolishNotationStack = s.build_notation(lexems_input);
	GoodPolishNotationStack = new Stack<Lexema>(PolishNotationStack->GetSize());
	while (!PolishNotationStack->IsEmpty())
	{
		GoodPolishNotationStack->Push(PolishNotationStack->Put());
	}
	ReversePolishNotation r;
	res = r.Ñalculate(GoodPolishNotationStack);

	return res;
}