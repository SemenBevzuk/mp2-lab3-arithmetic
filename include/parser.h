
#pragma once
#include "lexema.h"

using namespace std;
class Parser
{
private:
	void AddVariable(string var, Lexema* res, int index, int pos);
	void AddDigit(string var, Lexema* res, int index, int *for_index, int pos);
	void AddAddOperation(string var, Lexema* res, int index, int pos);
	void AddMinusOperation(string var, Lexema* res, int index, int pos);
	void AddMultiplyOperation(string var, Lexema* res, int index, int pos);
	void AddDivideOperation(string var, Lexema* res, int index, int pos);
	void AddOperationUnary(string var, Lexema* res, int index, int pos);
	void AddOpenBracket(string var, Lexema* res, int index, int pos);
	void AddCloseBracket(string var, Lexema* res, int index, int pos);

	bool IsVariable(string str, int index);
	bool IsDigit(string str, int index);
	bool IsBinaryOperaion(string str, int index);
	bool IsAddOperation(string str, int index);
	bool IsMunisOperation(string str, int index);
	bool IsMultiplyOperation(string str, int index);
	bool IsDivideOperation(string str, int index);
	bool IsOperationUnary(string str, int index);
	bool IsOpenBracket(string str, int index);
	bool IsCloseBracket(string str, int index);
public:
	Lexema* Parse(string input);
};
