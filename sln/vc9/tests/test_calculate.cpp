#include <gtest.h>
#include "calculate.h"

TEST(Calculate, can_expression_whith_add) {
	Calculator Calc;
	string input = "1+2+3";
	double res = Calc.Calculate(input);
	ASSERT_EQ(1 + 2 + 3, res);
}

TEST(Calculate, can_expression_whith_unary_minus) {
	Calculator Calc;
	string input = "-2*5+2";
	double res = Calc.Calculate(input);
	ASSERT_EQ(-2 * 5 + 2, res);
}

TEST(Calculate, can_calculate_expression_like_batya) {
	Calculator Calc;
	string input = "-(50*120+3/4)*(27*(-2))+(22+33/11)";
	double res = Calc.Calculate(input);
	ASSERT_EQ(-(50 * 120 + 3 / 4.0)*(27 * (-2)) + (22 + 33 / 11.0), res);
}

TEST(Calculate, can_calculate_expression_almost_like_batya) {
	Calculator Calc;
	string input = "-(500+3/4)*27";
	double res = Calc.Calculate(input);
	//ASSERT_EQ(-(50 * 120 + 3 / 4.0)*27, res);
	ASSERT_DOUBLE_EQ(-(500+3 / 4.0)*27, res);
}