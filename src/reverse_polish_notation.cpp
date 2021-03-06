#include "reverse_polish_notation.h"

double ReversePolishNotation::�alculate(Stack<Lexema>* input) {
	Lexema element;
	Lexema res;
	double operation_result;
	double left, right;

	while (!input->IsEmpty()) {
		element = input->Put();
		if (element.GetType() == Type_Lexems::var) {
			if (!result->IsFull()) {
				result->Push(element);
			}
			else {
				throw "������������ �����";
			}
		}
		if (element.GetType() == Type_Lexems::digit) {
			if (!result->IsFull()) {
				result->Push(element);
			}
			else {
				throw "������������ �����";
			}
		}
		if (element.GetType() == Type_Lexems::add) {
			if (!result->IsFull()) {

				left = result->Put().GetDecimalValue();
				right = result->Put().GetDecimalValue();
				operation_result = left + right;
				element = Lexema(Type_Lexems::digit, operation_result);
				result->Push(element);
			}
			else {
				throw "������������ �����";
			}
		}
		if (element.GetType() == Type_Lexems::minus) {
			if (!result->IsFull()) {

				right = result->Put().GetDecimalValue();
				left = result->Put().GetDecimalValue();

				operation_result = left - right;
				element = Lexema(Type_Lexems::digit, operation_result);
				result->Push(element);
			}
			else {
				throw "������������ �����";
			}
		}
		if (element.GetType() == Type_Lexems::multiply) {
			if (!result->IsFull()) {

				left = result->Put().GetDecimalValue();
				right = result->Put().GetDecimalValue();

				operation_result = left * right;
				element = Lexema(Type_Lexems::digit, operation_result);
				result->Push(element);
			}
			else {
				throw "������������ �����";
			}
		}
		if (element.GetType() == Type_Lexems::divide) {
			if (!result->IsFull()) {

				right = result->Put().GetDecimalValue();
				left = result->Put().GetDecimalValue();

				operation_result = left / right;
				element = Lexema(Type_Lexems::digit, operation_result);
				result->Push(element);
			}
			else {
				throw "������������ �����";
			}
		}
		if (element.GetType() == Type_Lexems::unary_operetion_minus) {
			if (!result->IsFull()) {

				left = result->Put().GetDecimalValue();

				operation_result = -left;
				element = Lexema(Type_Lexems::digit, operation_result);
				result->Push(element);
			}
			else {
				throw "������������ �����";
			}
		}
	}
	return result->Put().GetDecimalValue();;
}