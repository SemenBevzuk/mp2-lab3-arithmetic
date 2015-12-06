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

TEST(Calculate, can_calculate_some_expression) {
	Calculator Calc;
	string input = "-(50*120+3/4)*(27*(-2))+(22+33/11)";
	double res = Calc.Calculate(input);
	ASSERT_EQ(-(50 * 120 + 3 / 4.0)*(27 * (-2)) + (22 + 33 / 11.0), res);
}

TEST(Calculate, can_calculate_expression_whith_two_bracket_and_minus) {
	Calculator Calc;
	string input = "(500-27*7)-(25*3+100)";
	double res = Calc.Calculate(input);
	ASSERT_EQ((500 - 27 * 7) - (25 * 3 + 100), res);
}

TEST(Calculate, can_calculate_expression_double) {
	Calculator Calc;
	string input = "2.2+3.8";
	double res = Calc.Calculate(input);
	cout << res;
	ASSERT_EQ(2.2 + 3.8, res);
}

TEST(Calculate, can_calculate_expression_double_2) {
	Calculator Calc;
	string input = "(2+2.3)*(3.4-2.9)";
	double res = Calc.Calculate(input);
	cout << res;
	ASSERT_EQ((2 + 2.3)*(3.4 - 2.9), res);
}
