#include "gtest.h"
#include "reverse_polish_notation.h"

TEST(PolishNotation, can_expression_whith_add) {
	std::string input = "1+2+3";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Corrector c;
	Stack<Error>* errors;
	Stack<Lexema> PolishNotStack;
	double res;
	errors = c.CheckExpression(lexems_input);
	while (!errors->IsEmpty())
	{
		Error err = errors->Put();
		string str = err.GetText();
		cout << str << err.GetPosition()<<endl;
	}

	ExpressionBuilder builder(lexems_input, 5);
	Expression* expression = builder.Build();
	expression->PushTo(&PolishNotStack);
	ReversePolishNotation  PolishNotation;

	res = PolishNotation.Ñalculate(&PolishNotStack);

	ASSERT_EQ(1+2+3, res);
}

TEST(PolishNotation, can_expression_whith_minus) {
	std::string input = "1+2-3";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Corrector c;
	Stack<Error>* errors;
	Stack<Lexema> PolishNotStack;
	double res;
	errors = c.CheckExpression(lexems_input);
	while (!errors->IsEmpty()) {
		Error err = errors->Put();
		string str = err.GetText();
		cout << str << err.GetPosition() << endl;
	}

	ExpressionBuilder builder(lexems_input, 5);
	Expression* expression = builder.Build();
	expression->PushTo(&PolishNotStack);
	ReversePolishNotation  PolishNotation;

	res = PolishNotation.Ñalculate(&PolishNotStack);

	ASSERT_EQ(1 + 2 - 3, res);
}

TEST(PolishNotation, can_expression_whith_multiply) {
	std::string input = "1+2*3";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Corrector c;
	Stack<Error>* errors;
	Stack<Lexema> PolishNotStack;
	double res;
	errors = c.CheckExpression(lexems_input);
	while (!errors->IsEmpty()) {
		Error err = errors->Put();
		string str = err.GetText();
		cout << str << err.GetPosition() << endl;
	}

	ExpressionBuilder builder(lexems_input, 5);
	Expression* expression = builder.Build();
	expression->PushTo(&PolishNotStack);
	ReversePolishNotation  PolishNotation;

	res = PolishNotation.Ñalculate(&PolishNotStack);

	ASSERT_EQ(1 + 2 * 3, res);
}
//TEST(PolishNotation, can_expression_whith_divide) {
//	std::string input = "1*2/4";
//	Parser p;
//	Lexema* lexems_input = p.Parse(input);
//	Corrector c;
//	Stack<Error>* errors;
//	Stack<Lexema> PolishNotStack;
//	double res;
//	errors = c.CheckExpression(lexems_input);
//	while (!errors->IsEmpty()) {
//		Error err = errors->Put();
//		string str = err.GetText();
//		cout << str << err.GetPosition() << endl;
//	}
//
//	ExpressionBuilder builder(lexems_input, input.size());
//	Expression* expression = builder.Build();
//	expression->PushTo(&PolishNotStack);
//	ReversePolishNotation  PolishNotation;
//
//	res = PolishNotation.Ñalculate(&PolishNotStack);
//
//	ASSERT_EQ(1*2/4.0, res);
//}