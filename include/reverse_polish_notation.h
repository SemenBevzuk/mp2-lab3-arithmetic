#pragma once
#include "parser.h"
#include "corrector.h"
#include "stack.h"
#include "expression_builder.h"

class ReversePolishNotation
{
public:
	ReversePolishNotation() { result = new Stack<Lexema>(); }
	
	double �alculate(Stack<Lexema>* input);
private:
	Stack<Lexema>* result;
};