#include "stack.h"
#include "expression.h"
#include "expression_builder.h"
#include <gtest.h>
#include "IConsole.h"

TEST(Stack_lexem, can_push_expression_whith_add) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("1+2", NULL);
	Expression* expression = builder.Build();
	expression->PushTo(&stack);
	ASSERT_EQ("2", stack.Put().GetValue());
	ASSERT_EQ("1", stack.Put().GetValue());
	ASSERT_EQ("+", stack.Put().GetValue());
}

TEST(Stack_lexem, can_push_expression_whith_any_add) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("1+2+3", NULL);
	Expression* expression = builder.Build();
	double x = expression->Calculate();
	expression->PushTo(&stack);;

	ASSERT_EQ("3", stack.Put().GetValue());
	ASSERT_EQ("2", stack.Put().GetValue());
	ASSERT_EQ("+", stack.Put().GetValue());
	ASSERT_EQ("1", stack.Put().GetValue());
	ASSERT_EQ("+", stack.Put().GetValue());
}

TEST(Stack_lexem, can_push_expression_whith_bracket) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("(1+2)*4", NULL);
	Expression* expression = builder.Build();
	double x = expression->Calculate();
	expression->PushTo(&stack);;

	ASSERT_EQ("4", stack.Put().GetValue());
	ASSERT_EQ("2", stack.Put().GetValue());
	ASSERT_EQ("1", stack.Put().GetValue());
	ASSERT_EQ("+", stack.Put().GetValue());
	ASSERT_EQ("*", stack.Put().GetValue());
}

TEST(Stack_lexem, can_read_variable) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("a", new ConsoleStub(1));
	Expression* expression = builder.Build();
	expression->PushTo(&stack);;

	ASSERT_EQ("1", stack.Put().GetValue());
}
