#include "corrector.h"
#include "stack.h"
#include <string>

Stack<Error>* Corrector::CheckExpression(Lexema *input) {
	int i = 0;
	int count_bracket = 0;
	while (input[i].GetType() != Type_Lexems::terminal) {
		if (IsDigit(input[i])) {
			if(IsDigitRight(input[i]) == false){
				AddError(input[i].GetPosition(), "Ошибка в числе. Позиция ошибки: ");
			}
		}
		if (IsBinaryOperaion(input[i]))
		{
			if (input[i+1].GetType() == Type_Lexems::terminal)
			{
				AddError(input[i].GetPosition(), "Ошибка в бинарной операции. Позиция ошибки: ");
			}
			if (input[i + 1].GetType() != Type_Lexems::terminal && IsBinaryOperaion(input[i+1])) {
				AddError(input[i].GetPosition(), "Ошибка в повторе бинарной операций. Позиция ошибки: ");
			}
		}
		if (IsOperationUnary(input[i]))
		{
			if (input[i + 1].GetType() == Type_Lexems::terminal) {
				AddError(input[i].GetPosition(), "Ошибка в унарной операции. Позиция ошибки: ");
			}
		}
		if (IsOpenBracket(input[i]))
		{
			count_bracket++;
		}
		if (IsCloseBracket(input[i]))
		{
			count_bracket--;
			if (count_bracket<0)
			{
				AddError(input[i].GetPosition(), "Ошибка в закрывающей скобке. Позиция ошибки: ");
			}
		}
		i++;
	}
	if (count_bracket != 0)
	{
		AddError("Ошибка в скобках.");
	}
	return &errors;
}

void Corrector::AddError(int pos, string s)
{
	if (errors.IsFull())
	{
		throw "Стэк перепполнен";
	}
	errors.Push(Error(pos,s));
}

void Corrector::AddError(string s)
{
	if (errors.IsFull()) {
		throw "Стэк перепполнен";
	}
	errors.Push(Error(s));
}

bool Corrector::IsDigitRight(Lexema lex)
{
	string str = lex.GetValue();
	int i = 0;
	int count_points = 0;

	if (str[0] == '.') {
		return false;
	}
	for (std::string::iterator it = str.begin(); it != str.end(); ++it, i++) {
		if (str[i] == '.') {
			count_points++;
		}
	}
	if (count_points>1) {
		return false;
	}
	return true;
}

bool Corrector::IsDigit(Lexema lex)
{
	if (lex.GetType() == Type_Lexems::digit)
	{
		return true;
	}
	return false;
}

bool Corrector::IsBinaryOperaion(Lexema lex)
{
	if (lex.GetType() == Type_Lexems::add ||
		lex.GetType() == Type_Lexems::minus ||
		lex.GetType() == Type_Lexems::multiply ||
		lex.GetType() == Type_Lexems::divide) {
		return true;
	}
	return false;
}

bool Corrector::IsOperationUnary(Lexema lex)
{
	if (lex.GetType() == Type_Lexems::unary_operetion_minus) {
		return true;
	}
	return false;
}

bool Corrector::IsOpenBracket(Lexema lex)
{
	if (lex.GetType() == Type_Lexems::open_bracet) {
		return true;
	}
	return false;
}

bool Corrector::IsCloseBracket(Lexema lex)
{
	if (lex.GetType() == Type_Lexems::close_bracket) {
		return true;
	}
	return false;
}