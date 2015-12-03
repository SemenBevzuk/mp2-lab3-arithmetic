#include "aggregate.h"
#include <iostream>
#include <string>


using namespace std;

bool Aggregate::IsVar(Lexema lex)
{
	if (lex.GetType() == Type_Lexems::var)
	{
		return true;
	}
	return false;
}

bool Aggregate::IsSetInRegister(string VarName)
{
	for (int i = 0; i < RegisterVariables.size(); i++)
	{
		if (RegisterVariables[i].GetName() == VarName)
		{
			return true;
		}
	}
	return false;
}

Variable Aggregate::FindVariable(string VarName) 
{
	for (int i = 0; i < RegisterVariables.size();i++)
	{
		if (RegisterVariables[i].GetName() == VarName)
		{
			return RegisterVariables[i];
		}
	}
}

void Aggregate::FillVar(Lexema* input)
{
	int i = 0;
	bool haslexem = (input[i].GetType()!=Type_Lexems::terminal);
	string s;
	Variable temp;
	double variable;
	while (haslexem)
	{
		if (IsVar(input[i]))
		{
			if (IsSetInRegister(input[i].GetValue()))
			{
				temp = FindVariable(input[i].GetValue());
				input[i].SetDecimal(temp.GetValue());
			}
			else 
			{
				s = input[i].GetValue();
				cout << "Введите значение переменной " << s << ": ";
				cin >> variable;
				cout << endl;
				RegisterVariables.push_back(Variable(s, variable));
				input[i].SetDecimal(variable);
			}
		}
		i++;
		haslexem = (input[i].GetType() != Type_Lexems::terminal);
	}
}
