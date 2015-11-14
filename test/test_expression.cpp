#include "gtest.h"
#include "expression.h"

TEST(Expression, can_calc_digit)
{
	Digit a(1);
	EXPECT_EQ(1, a.Calculate());
}

TEST(Expression, can_calc_var)
{
	Var a;
	a.SetValue(1);
	EXPECT_EQ(1, a.Calculate());
}

TEST(Expression, can_set_digit) {
	Digit a(1);
	Digit b(0);
	b = a;
	EXPECT_EQ(1, b.Calculate());
}

TEST(Expression, can_calc_unary_minus)
{
	UnaryMinus a;
	a.SetExpression(new Digit(1));
	EXPECT_EQ(-1, a.Calculate());
}

TEST(Expression, can_calc_plus)
{
	Add add;
	add.SetLeft(new Digit(1));
	add.SetRight(new Digit(2));
	EXPECT_EQ(1 + 2, add.Calculate());
}

TEST(Expression, can_calc_minus) {
	Minus minus;
	minus.SetLeft(new Digit(1));
	minus.SetRight(new Digit(2));
	EXPECT_EQ(1 - 2, minus.Calculate());
}

TEST(Expression, can_calc_multiply) {
	Multiply m;
	m.SetLeft(new Digit(2));
	m.SetRight(new Digit(3));
	EXPECT_EQ(2 * 3, m.Calculate());
}

TEST(Expression, can_calc_divide) {
	Divide d;
	d.SetLeft(new Digit(3));
	d.SetRight(new Digit(2));
	EXPECT_EQ(3.0/ 2.0, d.Calculate());
}

TEST(Expression, can_calc_expression) {
	Add s;
	s.SetLeft(new Digit(1));
	Multiply m;
	m.SetLeft(new Digit(2));
	m.SetRight(new Digit(3));
	s.SetRight(&m);
	EXPECT_EQ(1+2*3, s.Calculate());
}