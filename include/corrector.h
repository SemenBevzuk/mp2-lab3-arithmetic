#pragma once
#include "parser.h"

class Error //нет ошибки - верну NULL
{
private:
	int Position;
	string Text;
public:
	Error(int pos, string s) { Position = pos; Text = s;}
	int GetPosition() const { return Position; }
	string GetText() const { return Text; }
};
class Corrector
{
public:
	bool CheckExpression(Lexema *input);
private:
	bool IsDigitRight(Lexema lex);


	bool IsDigit(Lexema lex);
	bool IsBinaryOperaion(Lexema lex);
	bool IsOperationUnary(Lexema lex);
	bool IsOpenBracket(Lexema lex);
	bool IsCloseBracket(Lexema lex);
};