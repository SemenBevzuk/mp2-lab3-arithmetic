#include <gtest.h>
#include "switch.h"

TEST(Switch, can_switch_expression_whith_add) {
	std::string input = "1+2";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
	EXPECT_EQ("1", exp->Put().GetValue());
}

TEST(Switch, can_switch_1) {
	std::string input = "(2+3*7)";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("*", exp->Put().GetValue());
	EXPECT_EQ("7", exp->Put().GetValue());
	EXPECT_EQ("3", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
}

TEST(Switch, can_switch_2) {
	std::string input = "(2+3*7)*3.5";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("*", exp->Put().GetValue());
	EXPECT_EQ("3.5", exp->Put().GetValue());
	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("*", exp->Put().GetValue());
	EXPECT_EQ("7", exp->Put().GetValue());
	EXPECT_EQ("3", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
}

TEST(Switch, can_switch_3) {
	std::string input = "(2+3)*3.5-22";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("-", exp->Put().GetValue());
	EXPECT_EQ("22", exp->Put().GetValue());
	EXPECT_EQ("*", exp->Put().GetValue());
	EXPECT_EQ("3.5", exp->Put().GetValue());
	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("3", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
}

TEST(Switch, can_switch_4) {
	std::string input = "2+3*4";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("*", exp->Put().GetValue());
	EXPECT_EQ("4", exp->Put().GetValue());
	EXPECT_EQ("3", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
}
TEST(Switch, can_switch_5) {
	std::string input = "-2+3";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("3", exp->Put().GetValue());
	EXPECT_EQ(Type_Lexems::unary_operetion_minus, exp->Put().GetType());
	EXPECT_EQ("2", exp->Put().GetValue());
}
TEST(Switch, can_switch_6) {
	std::string input = "-(2+3)";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ(Type_Lexems::unary_operetion_minus, exp->Put().GetType());
	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("3", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
}

TEST(Switch, can_switch_7) {
	std::string input = "2*5+2";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
	EXPECT_EQ("*", exp->Put().GetValue());
	EXPECT_EQ("5", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
}

TEST(Switch, can_switch_8) {
	std::string input = "-2*5+2";
	Parser p;
	Lexema* lexems_input = p.Parse(input);
	Switch s;
	Stack<Lexema>* exp;

	exp = s.build_notation(lexems_input);

	EXPECT_EQ("+", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
	EXPECT_EQ("*", exp->Put().GetValue());
	EXPECT_EQ("5", exp->Put().GetValue());
	EXPECT_EQ("-", exp->Put().GetValue());
	EXPECT_EQ("2", exp->Put().GetValue());
}