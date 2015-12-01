#include "parser.h"
#include <string>

//LEXEMA---

Lexema::Lexema()
{
	Type = Type_Lexems::terminal;
	Value = "0";
	Position = -1;
};

Lexema::Lexema(Type_Lexems type, string val, int pos) {
	Type = type;
	Value = val;
	Position = pos;
	if (type == Type_Lexems::digit) {
		Decimal = stod(val);
	}
}

Lexema::Lexema(Type_Lexems type, double dec)
{
	Type = type;
	Decimal = dec;
}

bool Lexema::operator==(const Lexema &v) const{
	if (Type != v.Type) {
		return false;
	}
	if (Value.length() != v.Value.length()) {
		return false;
	}

	for (int i = 0; i < Value.length(); i++) {
		if (Value[i] != v.Value[i]) {
			return false;
		}
	}
	return true;
}

//PARSER---

void Parser::AddVariable(string v, Lexema* res, int index, int pos)
{
	string variable;
	variable += v;
	res[index] = Lexema(Type_Lexems::var, variable, pos);
}
void Parser::AddDigit(string str, Lexema* res, int index, int *for_index, int pos)
{
	string variable;
	string point = ".";

	while (str.substr(*for_index, 1) == point || IsDigit(str, *for_index))
	{
		variable += str.substr(*for_index, 1);
		(*for_index)++;
		if (*for_index == str.length())
		{
			break;
		}
	}
	res[index] = Lexema(Type_Lexems::digit, variable, pos);
}
void Parser::AddAddOperation(string var, Lexema* res, int index, int pos)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::add, variable, pos);
}

void Parser::AddMinusOperation(string var, Lexema* res, int index, int pos)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::minus, variable, pos);
}

void Parser::AddMultiplyOperation(string var, Lexema* res, int index, int pos)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::multiply, variable, pos);
}

void Parser::AddDivideOperation(string var, Lexema* res, int index, int pos)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::divide, variable, pos);
}

void Parser::AddOperationUnary(string var, Lexema* res, int index, int pos)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::unary_operetion_minus, variable, pos);
}
void Parser::AddOpenBracket(string var, Lexema* res, int index, int pos)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::open_bracet, variable, pos);
}
void Parser::AddCloseBracket(string var, Lexema* res, int index, int pos)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::close_bracket, variable, pos);
}
bool Parser::IsVariable(string str, int index)
{
	try {
		return isalpha(str[index]);
	}
	catch (...) {
		return false;
	}
}
bool Parser::IsDigit(string str, int index)
{
	try {
		stod(str.substr(index, 1));
	}
	catch (...) {
		return false;
	}
	return stod(str.substr(index, 1)) >= 0 && stod(str.substr(index, 1)) <= 9;
}
bool Parser::IsOperationUnary(string str, int index)
{
	return (str[index] == '-') && (index == 0 || IsOpenBracket(str, index-1) || IsBinaryOperaion(str, index - 1));
}
bool Parser::IsBinaryOperaion(string str, int index)
{
	return (index != 0) &&
		(index < str.length() - 1) &&
		(IsDigit(str, index - 1) || IsVariable(str, index - 1) || IsCloseBracket(str, index - 1)) &&
		(IsDigit(str, index + 1) || IsVariable(str, index + 1) || IsOpenBracket(str, index + 1));
}
bool Parser::IsAddOperation(string str, int index)
{
	return (str[index] == '+') && IsBinaryOperaion(str, index);
}
bool Parser::IsMunisOperation(string str, int index)
{
	return (str[index] == '-') && IsBinaryOperaion(str, index);
}
bool Parser::IsMultiplyOperation(string str, int index)
{
	return (str[index] == '*') && IsBinaryOperaion(str, index);
}
bool Parser::IsDivideOperation(string str, int index)
{
	return (str[index] == '/') && IsBinaryOperaion(str, index);
}
bool Parser::IsOpenBracket(string str, int index)
{
	return str[index] == '(';
}
bool Parser::IsCloseBracket(string str, int index)
{
	return str[index] == ')';
}


Lexema* Parser::Parse(string input) {
	Lexema* result = new Lexema[input.length()+1];
	for (int i = 0; i < input.length()+1; i++)
	{
		result[i] = Lexema(Type_Lexems::terminal, "", i);
	}

	int lexemaIndex = 0;

	for (int i = 0; i < input.length(); i++) {
		if (IsVariable(input,i)) {
			AddVariable(input.substr(i,1), result, lexemaIndex, i);
			
			lexemaIndex++;
			continue;
		}
		if (IsOperationUnary(input,i))
		{
			AddOperationUnary(input.substr(i, 1), result, lexemaIndex, i);
			lexemaIndex++;
			continue;
		}
		if (IsAddOperation(input,i)) {
			AddAddOperation(input.substr(i, 1), result, lexemaIndex, i);
			lexemaIndex++;
			continue;
		}
		if (IsMunisOperation(input,i)) {
			AddMinusOperation(input.substr(i, 1), result, lexemaIndex, i);
			lexemaIndex++;
			continue;
		}
		if (IsMultiplyOperation(input,i)) {
			AddMultiplyOperation(input.substr(i, 1), result, lexemaIndex, i);
			lexemaIndex++;
			continue;
		}
		if (IsDivideOperation(input,i)) {
			AddDivideOperation(input.substr(i, 1), result, lexemaIndex, i);
			lexemaIndex++;
			continue;
		}
		if (IsOpenBracket(input,i))
		{
			AddOpenBracket(input.substr(i, 1), result, lexemaIndex, i);
			lexemaIndex++;
			continue;
		}
		if (IsCloseBracket(input,i)) {
			AddCloseBracket(input.substr(i, 1), result, lexemaIndex, i);
			lexemaIndex++;
			continue;
		}
		if (IsDigit(input,i))
		{
			int j = 0;
			AddDigit(input.substr(i), result, lexemaIndex, &j, i);
			i += j-1;
			lexemaIndex++;
			continue;
		}
	}
	return result;
}