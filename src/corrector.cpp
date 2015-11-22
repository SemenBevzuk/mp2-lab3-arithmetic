#include "corrector.h"

bool Corrector::CheckExpression(Lexema *input) {
	int i = 0;
	while (input[i].GetType() != Type_Lexems::terminal) {
		if (IsDigit(input[i])) {
			IsDigitRight(input[i]);
		}
		i++;
	}
	return true;
}

bool Corrector::IsDigitRight(Lexema lex)
{
	string str = lex.GetValue();
	int i = 0;
	int count_points;
	if (str[0]=='.')
	{
		return false;
	}
	for (std::string::iterator it = str.begin(); it != str.end(); ++it, i++)
	{
		if (str[i] == '.')
		{
			count_points++;
		}
	}
	if (count_points>1) 
	{
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