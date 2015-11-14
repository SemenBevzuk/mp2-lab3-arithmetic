#include <gtest.h>
#include "parser.h"

TEST(Parser, can_pars_var) {
	Lexema result(var, "a");
	std::string input = "a";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_digit) {
	Lexema result(digit, "123");
	std::string input = "123";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_digit_whith_comma) {
	Lexema result(digit, "123.456");
	std::string input = "123.456";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_binary_operation) {
	Lexema result(binary_operation, "+");
	std::string input = "a+b";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[1]);
}
TEST(Parser, can_pars_unary_operation) {
	Lexema result(unary_operetion, "-");
	std::string input = "-a";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_open_bracket) {
	Lexema result(open_bracet, "(");
	std::string input = "(-a)";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_close_bracket) {
	Lexema result(close_bracket, ")");
	std::string input = "(-a)";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[3]);
}
TEST(Parser, can_pars) {
	Lexema result(binary_operation, "-");
	std::string input = "(a+b*7)*3.5-22";
	Parser p;
	p.Parse(input);
	EXPECT_EQ(result, p.Parse(input)[9]);
}