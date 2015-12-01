﻿
#pragma once
#include <iostream>

using namespace std;

enum Type_Lexems { var, digit, unary_operetion_minus, open_bracet, close_bracket, terminal, add, minus, multiply, divide};

class Lexema
{
private:
	Type_Lexems Type;
	string Value;
	int Position;
	double Decimal;


public:
	Lexema();
	Lexema(Type_Lexems type, string val, int pos=-1);
	Lexema(Type_Lexems type, double dec);
	bool operator==(const Lexema &v) const;
	Type_Lexems GetType() const { return Type; }
	string GetValue() const { return Value; }
	double GetDecimalValue() const { return Decimal; }
	void SetPosition(int pos) { Position = pos; }
	void SetDecimal(double dec) { Decimal = dec; }
	int GetPosition() { return Position; }

	friend ostream& operator<<(ostream &out, const Lexema &l) {
		out << l.Type << endl;
		out << l.Value.c_str() << endl;
		return out;
	}
};


class Parser
{
private:
	void AddVariable(string var, Lexema* res, int index, int pos);
	void AddDigit(string var, Lexema* res, int index, int *for_index, int pos);
	void AddAddOperation(string var, Lexema* res, int index, int pos);
	void AddMinusOperation(string var, Lexema* res, int index, int pos);
	void AddMultiplyOperation(string var, Lexema* res, int index, int pos);
	void AddDivideOperation(string var, Lexema* res, int index, int pos);
	void AddOperationUnary(string var, Lexema* res, int index, int pos);
	void AddOpenBracket(string var, Lexema* res, int index, int pos);
	void AddCloseBracket(string var, Lexema* res, int index, int pos);

	bool IsVariable(string str, int index);
	bool IsDigit(string str, int index);
	bool IsBinaryOperaion(string str, int index);
	bool IsAddOperation(string str, int index);
	bool IsMunisOperation(string str, int index);
	bool IsMultiplyOperation(string str, int index);
	bool IsDivideOperation(string str, int index);
	bool IsOperationUnary(string str, int index);
	bool IsOpenBracket(string str, int index);
	bool IsCloseBracket(string str, int index);
public:
	Lexema* Parse(string input);
};
