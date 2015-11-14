#include "gtest.h"
#include "expression_builder.h"

TEST(Expression_Builder, can_build_digit)
{
	ExpressionBuilder builder("1");
	Expression* expression = builder.Build();
	ASSERT_EQ(1,expression->Calculate());
}

TEST(Expression_Builder, can_build_digit_plus) {
	ExpressionBuilder builder("1+2");
	Expression* expression = builder.Build();
	ASSERT_EQ(1+2, expression->Calculate());
}