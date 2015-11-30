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
