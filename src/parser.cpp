#include "parser.h"
#include <string>

//LEXEMA---

Lexema::Lexema() {};

Lexema::Lexema(Type_Lexems type, string val) {
	Type = type;
	Value = val;
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

void Parser::AddVariable(string v, Lexema* res, int index)
{
	string variable;
	variable += v;
	res[index] = Lexema(Type_Lexems::var, variable);
}
void Parser::AddDigit(string str, Lexema* res, int index, int *for_index)
{
	string variable;
	string point = ".";

	while ((str.substr(*for_index, 1) == point) || (stod(str.substr(*for_index, 1)) >= 0 && stod(str.substr(*for_index, 1)) <= 9))
	{
		variable += str.substr(*for_index, 1);
		(*for_index)++;
		if (*for_index == str.length())
		{
			break;
		}
	}
	res[index] = Lexema(Type_Lexems::digit, variable);
}
void Parser::AddOperationBinary(string var, Lexema* res, int index)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::binary_operation, variable);
}
void Parser::AddOperationUnary(string var, Lexema* res, int index)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::unary_operetion, variable);
}
void Parser::AddOpenBracket(string var, Lexema* res, int index)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::open_bracet, variable);
}
void Parser::AddCloseBracket(string var, Lexema* res, int index)
{
	string variable;
	variable += var;
	res[index] = Lexema(Type_Lexems::close_bracket, variable);
}
bool Parser::IsVariable(string str, int index)
{
	return isalpha(str[index]);
}
bool Parser::IsDigit(string str, int index)
{
	return 0;
}
bool Parser::IsOperationUnary(string str, int index)
{
	return 0;
}
bool Parser::IsOperationBinary(string str, int index)
{
	return 0;
}
bool Parser::IsOpenBracket(string str, int index)
{
	return 0;
}
bool Parser::IsCloseBracket(string str, int index)
{
	return 0;
}




Lexema* Parser::Parse(string input) {
	Lexema* result = new Lexema[input.length()];

	int lexemaIndex = 0;

	for (int i = 0; i < input.length(); i++) {
		if (IsVariable(input,i)) {
			AddVariable(input.substr(i,1), result, lexemaIndex);
			lexemaIndex++;
			continue;
		}
		if ((input[i] == '-') && (i == 0 || input[i - 1] == '('))
		{
			AddOperationUnary(input.substr(i, 1), result, lexemaIndex);
			lexemaIndex++;
			continue;
		}
		if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') /*&& (result[lexemaIndex - 1].GetTypeLexems() != binary_operation)*/) {
			AddOperationBinary(input.substr(i, 1), result, lexemaIndex);
			lexemaIndex++;
			continue;
		}
		if (input[i] == '(')
		{
			AddOpenBracket(input.substr(i, 1), result, lexemaIndex);
			lexemaIndex++;
			continue;
		}
		if (input[i] == ')') {
			AddCloseBracket(input.substr(i, 1), result, lexemaIndex);
			lexemaIndex++;
			continue;
		}
		if (stod(input.substr(i, 1))>=0 && stod(input.substr(i, 1))<=9)
		{
			int j = 0;
			AddDigit(input.substr(i), result, lexemaIndex, &j);
			i += j;
			lexemaIndex++;
			continue;
		}
		
	}

	return result;
}