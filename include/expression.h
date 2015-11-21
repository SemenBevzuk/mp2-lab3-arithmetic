#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "stack.h"
#include <parser.h>

class Expression {
public:
	virtual ~Expression() {}
	virtual double Calculate() = 0;
	virtual Lexema ToLexem() = 0;
	virtual void PushTo(Stack<Lexema> *stack) { stack->Push(ToLexem()); };
};

class Digit : public Expression{
public:
	Digit(double value) { Value = value; }
	double Calculate() override { return Value; };
	Lexema ToLexem() override {
		std::ostringstream strs;
		strs << Value;
		std::string str = strs.str();
		return Lexema(Type_Lexems::digit, str);
	};
private:
	double Value;
};

class Var : public Expression {
public:
	double Calculate() override { 
	    //TODO: Нужна проверка IsSet, и ввод значения из консоли. Плюс подружить это с тестами.
		/*if (IsSet == false)
		{
			double x;
			std::cout << "Введите переменную "<< Name <<": ";
			std::cin >> x;
			std::cout << std::endl;
			Value = x;
			IsSet = true;
		}*/
		return Value; 
	};
	Var() {}
	Var(double value, std::string name)
	{
		Value = value;
		IsSet = true;
		Name = name;
	};

	void SetValue(double x) { Value = x; };

	Lexema ToLexem() override {
		std::ostringstream strs;
		strs << Value;
		std::string str = strs.str();
		return Lexema(Type_Lexems::var, str);
	};

private:
	double Value;
	bool IsSet = false;
	std::string Name = "";
};

class UnaryMinus : public Expression{
	Expression* expression;
public:
	void SetExpression(Expression* theExpression)
	{
		expression = theExpression;
	};
	double Calculate() override { return -expression->Calculate(); };
	Lexema ToLexem() override {
		return Lexema(Type_Lexems::unary_operetion_minus, "-");
	};
};

class BinaryOperation : public Expression {
public:
	void SetLeft(Expression* theLeft) { Left = theLeft; };
	void SetRight(Expression* theRight) { Right = theRight; };
	void PushTo(Stack<Lexema> *stack) override {
		stack->Push(Left->ToLexem());
		stack->Push(Right->ToLexem());
		stack->Push(ToLexem());
	};
protected:
	Expression* Left;
	Expression* Right;
};

class Multiply : public BinaryOperation
{
public:
	double Calculate() override { return Left->Calculate() * Right->Calculate(); };
	Lexema ToLexem() override {
		return Lexema(Type_Lexems::multiply, "*");
	};
};

class Divide : public BinaryOperation {
public:
	double Calculate() override { return Left->Calculate() / Right->Calculate(); };
	Lexema ToLexem() override {
		return Lexema(Type_Lexems::divide, "/");
	};
};

class Add : public BinaryOperation {
public:
	double Calculate() override { return Left->Calculate() + Right->Calculate(); };
	Lexema ToLexem() override {
		return Lexema(Type_Lexems::add, "+");
	};
};

class Minus : public BinaryOperation {
public:
	double Calculate() override { return Left->Calculate() - Right->Calculate(); };
	Lexema ToLexem() override {
		return Lexema(Type_Lexems::minus, "-");
	};
};