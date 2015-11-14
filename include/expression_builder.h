#include "expression.h"
#include "parser.h"

class ExpressionBuilder
{
private:
	Lexema* pLexems;
	Expression* getDigit(Lexema lexema);
	BinaryOperation* getBinaryOperation(Lexema lexema);
	Expression* build(Lexema* lexems, int* currentIndex);

public:
	ExpressionBuilder(string input) {
		Parser parser;
		pLexems = parser.Parse(input);
	}

	Digit* getDigit();
	Expression* Build();

	~ExpressionBuilder() {
		delete []pLexems;
	}
};