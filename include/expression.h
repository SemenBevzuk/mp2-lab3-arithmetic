#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "stack.h"
#include <parser.h>
#include "variable.h"

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

class VariableExpression : public Expression {
public:
	double Calculate() override { 
		return Var->GetValue(); 
	};
	VariableExpression(Variable* var)
	{
		Var = var;
	};
	Lexema ToLexem() override {
		std::ostringstream strs;
		strs << Var->GetValue(); //значение
		std::string str = strs.str();
		return Lexema(Type_Lexems::var, str);
	};
	void SetVar(double a)
	{
		Var->SetVariable(a);
	}

private:
	Variable* Var;
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
	void PushTo(Stack<Lexema> *stack) override {
		stack->Push(ToLexem());
		expression->PushTo(stack);
		
	};
};

class BinaryOperation : public Expression {
public:
	void SetLeft(Expression* theLeft) { Left = theLeft; };
	void SetRight(Expression* theRight) { Right = theRight; };
	void PushTo(Stack<Lexema> *stack) override {
		stack->Push(ToLexem());
		Left->PushTo(stack);
		Right->PushTo(stack);
		
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