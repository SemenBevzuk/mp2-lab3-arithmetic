#include "switch.h"

int Switch::LengthArray(Lexema* input) {
	int i = 0;
	while (input[i].GetType() != Type_Lexems::terminal) {
		i++;
	}
	return i;
}

bool Switch::IsBinaryOperation(Lexema lex) {
	if (lex.GetType() == Type_Lexems::add ||
		lex.GetType() == Type_Lexems::minus ||
		lex.GetType() == Type_Lexems::divide ||
		lex.GetType() == Type_Lexems::multiply)
	{
		return true;
	}
	return false;
}

void Switch::PushExpression(Lexema lex)
{
	expression->Push(lex);
}

void Switch::PushIntermediate(Lexema lex)
{
	intermediate->Push(lex);
}

void Switch::PushToExpressionFromIntermediate()
{
	expression->Push(intermediate->Put());
}

void Switch::DeleteBracets(Lexema lex)
{
	intermediate->Put();
}

Stack<Lexema>* Switch::build_notation(Lexema* input) {
	int Length = LengthArray(input);
	expression = new Stack<Lexema>(Length);
	intermediate = new Stack<Lexema>(Length);

	int i = -1;
	bool hasLexem = input[i+1].GetType() != Type_Lexems::terminal;
	Lexema lex;
	
	while (hasLexem) {
		i++;
		lex = input[i];
		hasLexem = input[i + 1].GetType() != Type_Lexems::terminal;

		if (lex.GetType() == Type_Lexems::digit || lex.GetType() == Type_Lexems::var)
		{
			PushExpression(lex);
			continue;
		}

		if (intermediate->IsEmpty())
		{
			PushIntermediate(lex); 
			continue;
		}

		Lexema lex_inter;
		lex_inter = intermediate->Peek();


		if (lex.GetType() == Type_Lexems::open_bracet || lex.GetType() == Type_Lexems::unary_operetion_minus) {
			PushIntermediate(lex);
			continue;
		}
		if ((lex.GetType() == Type_Lexems::divide || lex.GetType() == Type_Lexems::multiply) &&
			(lex_inter.GetType() == Type_Lexems::minus || lex_inter.GetType() == Type_Lexems::add)) {
			PushIntermediate(lex);
			continue;
		}
		if (IsBinaryOperation(lex) &&
			(lex_inter.GetType() == Type_Lexems::open_bracet)) {
			PushIntermediate(lex);
			continue;
		}

		if (lex.GetType() == Type_Lexems::close_bracket && lex_inter.GetType() == Type_Lexems::open_bracet)
		{
			DeleteBracets(lex);
			continue;
		}
		if (lex.GetType() == Type_Lexems::close_bracket)
		{
			while (intermediate->Peek().GetType() != Type_Lexems::open_bracet) {
				PushToExpressionFromIntermediate();
			}
			DeleteBracets(lex);
			continue;
		}
		
		PushToExpressionFromIntermediate();
		PushIntermediate(lex);
	}

	while (!intermediate->IsEmpty()) {
		PushToExpressionFromIntermediate();
	}
	return expression;
}


//| +�	* / ()
//| 4	1	1	1	1	1	5
//+ 2	2	2	1	1	1	2
//�	2	2	2	1	1	1	2
//* 2	2	2	2	2	1	2
/// 2	2	2	2	2	1	2
//(5	1	1	1	1	1	3
//����� ������������� ��������� ��������� :
//
//1)����� �� ������� ������������ � ������
//2)��������� �����, ������������� � ������, ��������������� � ������������ � ����
//3)�����, ����������� �� �������, � ��������� �����, ������������� � ������, ��������� � ��������
//4)���������.�������, ����������� �� �������� �����, ������������ ����� ������� � �������� �������� ������, ���� ������ ����� �������
//5)���������.��������� ������.����������� ������� ���� ����������� ��������������