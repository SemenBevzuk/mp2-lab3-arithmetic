#pragma once
#include "parser.h"
#include "variable.h"
#include <vector>

class Aggregate
{
private:
	vector<Variable> RegisterVariables;
	bool IsVar(Lexema lex);
	bool IsSetInRegister(string VarName);
	Variable FindVariable(string VarName);
public:
	void FillVar(Lexema *input);
};