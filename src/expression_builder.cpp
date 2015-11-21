#include "expression_builder.h"
#include <string>

Expression* ExpressionBuilder::getDigit(Lexema lexema)
{
	return new Digit(stod(lexema.GetValue()));
}

Expression* ExpressionBuilder::getVariable(Lexema lexema) {
	for (int i = 0; i < variables.size(); i++)
	{
		if (lexema.GetValue() == variables[i].GetName()) //value - имя
		{
			return new VariableExpression(&variables[i]);
		}
	}
	variables.push_back(Variable(lexema.GetValue()));

	return new VariableExpression(&variables[variables.size()-1]);
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
	int count_bracet = 0;
	int variable_count = 0;

	while (hasLexem)
	{
		Lexema lexema = lexems[*currentIndex];

		if (lexema.GetType() == Type_Lexems::var)
		{	
			expression = getVariable(lexema);
			(*currentIndex)++;
		}
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

		if (lexema.GetType() == Type_Lexems::open_bracet)
		{
			count_bracet = 1;
			int j = 1;

			while (count_bracet != 0)
			{
				if (lexems[*currentIndex + j].GetType() == Type_Lexems::open_bracet) {
					count_bracet++;
				}
				if (lexems[*currentIndex + j].GetType() == Type_Lexems::close_bracket)
				{
					count_bracet--;
				}
				j++;
			}
			ExpressionBuilder exp_builder(&lexems[*currentIndex + 1], j-2);
			Expression* exp = exp_builder.Build();
			expression = exp;
			(*currentIndex) += j;
		}

		if (lexema.GetType() == Type_Lexems::unary_operetion_minus)
		{
			UnaryMinus* operation;
			operation = new UnaryMinus;

			(*currentIndex)++;
			
			operation->SetExpression(build(lexems, currentIndex));
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