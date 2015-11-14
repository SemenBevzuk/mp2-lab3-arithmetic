#include "expression_builder.h"
#include <string>

Expression* ExpressionBuilder::getDigit(Lexema lexema)
{
	return new Digit(stod(lexema.GetValue()));
}

Expression* ExpressionBuilder::Build()
{
	int* index = new int;
	*index = 0;
	return build(pLexems, index);
};

Expression* ExpressionBuilder::build(Lexema* lexems, int* currentIndex)
{
	Expression* expression;
	bool hasLexem = lexems[*currentIndex].GetType() != Type_Lexems::terminal;
	while (hasLexem)
	{
		Lexema lexema = lexems[*currentIndex];
		if (lexema.GetType() == Type_Lexems::digit) {
			expression = getDigit(lexema);
			(*currentIndex)++;
		}
		if (lexema.GetType() == Type_Lexems::add || 
			lexema.GetType() == Type_Lexems::minus ||
			lexema.GetType() == Type_Lexems::multiply ||
			lexema.GetType() == Type_Lexems::divide)
		{
			BinaryOperation* operation = getBinaryOperation(lexema);
			operation->SetLeft(expression);
			(*currentIndex)++;
			operation->SetRight(build(lexems, currentIndex));
			expression = operation;
		}

		hasLexem = lexems[*currentIndex].GetType() != Type_Lexems::terminal;
	}
	return expression;
};

BinaryOperation* ExpressionBuilder::getBinaryOperation(Lexema lexema)
{
	switch (lexema.GetType())
	{
		case Type_Lexems::add: {
			return new Add();
			break;
		}		
		case Type_Lexems::minus: {
			return new Minus();
			break;
		}		
		case Type_Lexems::multiply: {
			return new Multiply();
			break;
		}		
		case Type_Lexems::divide: {
			return new Divide();
			break;
		}
	}
}