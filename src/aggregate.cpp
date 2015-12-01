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

void Aggregate::FillVar(Lexema* input)
{
	int i = 0;
	bool haslexem = (input[i].GetType()!=Type_Lexems::terminal);
	string s;
	double variable;
	while (haslexem)
	{
		if (IsVar(input[i]))
		{
			s = input[i].GetValue();
			cout << "Введите значение переменной " << s << ": ";
			cin >> variable;
			cout << endl;
			input[i].SetDecimal(variable);
		}
		i++;
		haslexem = (input[i].GetType() != Type_Lexems::terminal);
	}
}
