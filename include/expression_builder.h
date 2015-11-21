#pragma once
#include "expression.h"
#include <iostream>
#include <vector>

class ExpressionBuilder
{
private:
	Lexema* pLexems;

	Expression* getDigit(Lexema lexema);
	Expression* getVariable(Lexema lexema);

	BinaryOperation* getBinaryOperation(Lexema lexema);
	Expression* build(Lexema* lexems, int* currentIndex);

	std::vector<Variable> variables;

public:
	ExpressionBuilder(string input) {
		Parser parser;
		pLexems = parser.Parse(input);
	}
	
	ExpressionBuilder(Lexema* input, int size) {
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