#pragma once
#include "parser.h"
#include "corrector.h"
#include "stack.h"
#include "expression_builder.h"

class ReversePolishNotation
{
public:
	ReversePolishNotation() { result = new Stack<Lexema>(); }
	
	double Сalculate(Stack<Lexema>* input)
	{
		Lexema element;
		Lexema res;
		double operation_result;
		double left, right;
		res = Lexema(Type_Lexems::digit, "");
		while (!input->IsEmpty())
		{
			element = input->Put();
			if (element.GetType()==Type_Lexems::digit)
			{
				if (!result->IsFull())
				{
					result->Push(element);
				}
				else
				{
					throw "Переполнение стэка";
				}
			}
			if (element.GetType() == Type_Lexems::add) {
				if (!result->IsFull()) {
					
					left = stod(result->Put().GetValue());
					right = stod(result->Put().GetValue());
					
					operation_result = left+right;
					string str;
					std::ostringstream ost;
					ost << operation_result;
					str = ost.str();
					element = Lexema(Type_Lexems::digit, str);
					result->Push(element);
				}
				else {
					throw "Переполнение стэка";
				}
			}
			if (element.GetType() == Type_Lexems::minus) {
				if (!result->IsFull()) {

					left = stod(result->Put().GetValue());
					right = stod(result->Put().GetValue());
					
					operation_result = left - right;
					string str;
					std::ostringstream ost;
					ost << operation_result;
					str = ost.str();
					element = Lexema(Type_Lexems::digit, str);
					result->Push(element);
				}
				else {
					throw "Переполнение стэка";
				}
			}
			if (element.GetType() == Type_Lexems::multiply) {
				if (!result->IsFull()) {

					left = stod(result->Put().GetValue());
					right = stod(result->Put().GetValue());

					operation_result = left * right;
					string str;
					std::ostringstream ost;
					ost << operation_result;
					str = ost.str();
					element = Lexema(Type_Lexems::digit, str);
					result->Push(element);
				}
				else {
					throw "Переполнение стэка";
				}
			}
		}
		return stod(result->Put().GetValue());
	}
private:
	Stack<Lexema>* result;
};