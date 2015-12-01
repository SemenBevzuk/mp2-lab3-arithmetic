#pragma once
#include "parser.h"
#include "stack.h"

class Switch {
private:
	Stack<Lexema>* intermediate;
	Stack<Lexema>* expression;
	int LengthArray(Lexema *input);
	bool IsBinaryOperation(Lexema lex);

	void PushExpression(Lexema lex);
	void PushIntermediate(Lexema lex);
	void PushToExpressionFromIntermediate();
	void DeleteBracets(Lexema lex);

public:
	Stack<Lexema>* build_notation(Lexema *input);
};
