#pragma once
#include "parser.h"
#include "stack.h"

class Error
{
private:
	int Position;
	string Text;
public:
	Error() {Position = NULL, Text = ""; }
	Error(int pos, string s) { Position = pos; Text = s;}
	Error(string s) { Position = -1; Text = s; } //ошибка где-то в выражениия на ()
	int GetPosition() const { return Position; }
	string GetText() const { return Text; }
};
class Corrector
{
public:
	Stack<Error>* CheckExpression(Lexema *input);

private:
	Stack<Error> errors;

	void AddError(int pos, string s);
	void AddError(string s);

	bool IsDigitRight(Lexema lex);

	bool IsDigit(Lexema lex);
	bool IsBinaryOperaion(Lexema lex);
	bool IsOperationUnary(Lexema lex);
	bool IsOpenBracket(Lexema lex);
	bool IsCloseBracket(Lexema lex);
};