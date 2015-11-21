
#include "stack.h"
#include "expression.h"
#include "expression_builder.h"
#include <gtest.h>

TEST(Stack_lexem, can_push_expression_whith_add) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("1+2");
	Expression* expression = builder.Build();
	expression->PushTo(&stack);
	ASSERT_EQ("+", stack.Put().GetValue());
	ASSERT_EQ("2", stack.Put().GetValue());
	ASSERT_EQ("1", stack.Put().GetValue());
}

TEST(Stack_lexem, can_push_expression_whith_any_add) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("1+2+3");
	Expression* expression = builder.Build();
	double x = expression->Calculate();
	expression->PushTo(&stack);;

	ASSERT_EQ("+", stack.Put().GetValue());
	ASSERT_EQ("+", stack.Put().GetValue());
	ASSERT_EQ("3", stack.Put().GetValue());
	ASSERT_EQ("2", stack.Put().GetValue());
	ASSERT_EQ("1", stack.Put().GetValue());
}

TEST(Stack_lexem, can_push_expression_whith_bracket) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("(1+2)*4");
	Expression* expression = builder.Build();
	double x = expression->Calculate();
	expression->PushTo(&stack);;

	ASSERT_EQ("*", stack.Put().GetValue());
	ASSERT_EQ("4", stack.Put().GetValue());
	ASSERT_EQ("+", stack.Put().GetValue());
	ASSERT_EQ("2", stack.Put().GetValue());
	ASSERT_EQ("1", stack.Put().GetValue());
}