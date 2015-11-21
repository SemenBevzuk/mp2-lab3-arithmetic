
#include "stack.h"
#include "expression.h"
#include "expression_builder.h"
#include <gtest.h>


TEST(Stack_lexem, can_push_expression) {
	Stack < Lexema > stack(10);
	ExpressionBuilder builder("1+2");
	Expression* expression = builder.Build();
	expression->PushTo(&stack);
	ASSERT_EQ("+", stack.Put().GetValue());
	ASSERT_EQ("2", stack.Put().GetValue());
	ASSERT_EQ("1", stack.Put().GetValue());
	//ASSERT_NO_THROW(Stack<double> a);
}