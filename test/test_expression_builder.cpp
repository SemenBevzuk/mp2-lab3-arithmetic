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

TEST(Expression_Builder, can_build_digit_minus) {
	ExpressionBuilder builder("1-2");
	Expression* expression = builder.Build();
	ASSERT_EQ(1 - 2, expression->Calculate());
}

TEST(Expression_Builder, can_build_digit_multiply) {
	ExpressionBuilder builder("2*3");
	Expression* expression = builder.Build();
	ASSERT_EQ(2*3, expression->Calculate());
}

TEST(Expression_Builder, can_build_digit_divide) {
	ExpressionBuilder builder("3/2");
	Expression* expression = builder.Build();
	ASSERT_EQ(3.0/2.0, expression->Calculate());
}

TEST(Expression_Builder, can_build_expression_whith_bracket) {
	ExpressionBuilder builder("(1+2)*3");
	Expression* expression = builder.Build();
	ASSERT_EQ( (1+2)*3, expression->Calculate());
}