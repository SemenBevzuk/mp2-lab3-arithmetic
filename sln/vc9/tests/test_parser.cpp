#include <gtest.h>
#include "parser.h"

TEST(Parser, can_pars_var) {
	Lexema result(var, "a", 0);
	std::string input = "a";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_digit) {
	Lexema result(digit, "123", 0);
	std::string input = "123";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_digit_whith_comma) {
	Lexema result(digit, "123.456", 0);
	std::string input = "123.456";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_add_operation) {
	Lexema result(add, "+", 0);
	std::string input = "a+b";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[1]);
}
TEST(Parser, can_pars_unary_operation) {
	Lexema result(unary_operetion_minus, "-", 0);
	std::string input = "-a";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_open_bracket) {
	Lexema result(open_bracet, "(", 0);
	std::string input = "(-a)";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[0]);
}
TEST(Parser, can_pars_close_bracket) {
	Lexema result(close_bracket, ")", 0);
	std::string input = "(-a)";
	Parser p;

	EXPECT_EQ(result, p.Parse(input)[3]);
}
TEST(Parser, can_pars) {
	Lexema result(Type_Lexems::minus, "-", 0);
	std::string input = "(a+b*7)*3.5-22";
	Parser p;
	p.Parse(input);
	EXPECT_EQ(result, p.Parse(input)[9]);
}
TEST(Parser, lexema_know_index) {
	std::string input = "1+3.5-1";
	Parser p;
	p.Parse(input);
	EXPECT_EQ(0, p.Parse(input)[0].GetPosition());
	EXPECT_EQ(1, p.Parse(input)[1].GetPosition());
	EXPECT_EQ(2, p.Parse(input)[2].GetPosition());
	EXPECT_EQ(5, p.Parse(input)[3].GetPosition());
	EXPECT_EQ(6, p.Parse(input)[4].GetPosition());

}

TEST(Parser, double_point) {
	std::string input = "1+3..5";
	Parser p;
	ASSERT_NO_THROW(p.Parse(input));
	EXPECT_EQ("3..5", p.Parse(input)[2].GetValue());
}