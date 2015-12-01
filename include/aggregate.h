#pragma once
#include "parser.h"

class Aggregate
{
private:
	bool IsVar(Lexema lex);
public:
	void FillVar(Lexema *input);
};