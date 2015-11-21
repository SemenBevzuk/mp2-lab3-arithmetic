
#pragma once
#include "expression.h"

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
	
	ExpressionBuilder(Lexema* input, int size) {
		//pLexems = input;
		pLexems = new Lexema [size+1];
		for (int i = 0; i < size; i++) {
			pLexems[i] = input[i];
		}
		pLexems[size] = Lexema(Type_Lexems::terminal, "");
	}

	Digit* getDigit();
	Expression* Build();

	~ExpressionBuilder() {
		delete []pLexems;
	}
};