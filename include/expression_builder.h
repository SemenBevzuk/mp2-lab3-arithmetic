#pragma once
#include "expression.h"
#include <iostream>
#include <vector>
#include "IConsole.h"

class ExpressionBuilder
{
private:
	Lexema* pLexems;

	Expression* getDigit(Lexema lexema);
	Expression* getVariable(Lexema lexema);

	BinaryOperation* getBinaryOperation(Lexema lexema);
	Expression* build(Lexema* lexems, int* currentIndex);

	std::vector<Variable> variables;

	IConsole* console;

	void GetVariables() {
		for (int i = 0; i < variables.size(); i++) {
			if (!variables[i].IsSet()) {
				variables[i].SetVariable(console->GetValue(variables[i].GetName()));
			}
		}
	}
public:
	ExpressionBuilder(string input, IConsole* cons) {
		Parser parser;
		pLexems = parser.Parse(input);
		console = cons;
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