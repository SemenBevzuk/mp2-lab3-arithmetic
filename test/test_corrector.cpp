#include "gtest.h"
#include "corrector.h"
#include "parser.h"

TEST(Corrector, can_catch_error_digit) {
	Lexema *word = new Lexema[2];
	word[0] = Lexema(Type_Lexems::digit, "3..5", 0);
	word[1] = Lexema(Type_Lexems::terminal, "", 1);
	Corrector c;
	Stack<Error>* errors;
	Error res;

	errors = c.CheckExpression(word);
	res = errors->Put();
	
	EXPECT_EQ(0, res.GetPosition());
	EXPECT_EQ("Ошибка в числе. Позиция ошибки: ", res.GetText());
}
TEST(Corrector, can_catch_error_binary_operation) {
	Lexema *word = new Lexema[3];
	word[0] = Lexema(Type_Lexems::add, "+", 0);
	word[1] = Lexema(Type_Lexems::minus, "-", 1);
	word[2] = Lexema(Type_Lexems::terminal, "", 2);
	Corrector c;
	Stack<Error>* errors;
	Error res;

	errors = c.CheckExpression(word);
	res = errors->Put();

	EXPECT_EQ(1, res.GetPosition());
	EXPECT_EQ("Ошибка в бинарной операции. Позиция ошибки: ", res.GetText());
	res = errors->Put();
	EXPECT_EQ(0, res.GetPosition());
	EXPECT_EQ("Ошибка в повторе бинарной операций. Позиция ошибки: ", res.GetText());
}
TEST(Corrector, can_catch_error_unary_operation) {
	Lexema *word = new Lexema[3];
	word[0] = Lexema(Type_Lexems::digit, "1", 0);
	word[1] = Lexema(Type_Lexems::unary_operetion_minus, "-", 1);
	word[2] = Lexema(Type_Lexems::terminal, "", 2);
	Corrector c;
	Stack<Error>* errors;
	Error res;

	errors = c.CheckExpression(word);
	res = errors->Put();

	EXPECT_EQ(1, res.GetPosition());
	EXPECT_EQ("Ошибка в унарной операции. Позиция ошибки: ", res.GetText());
}
TEST(Corrector, can_catch_error_close_bracet) {
	Lexema *word = new Lexema[2];
	word[0] = Lexema(Type_Lexems::close_bracket, ")", 0);
	word[1] = Lexema(Type_Lexems::terminal, "", 1);
	Corrector c;
	Stack<Error>* errors;
	Error res;

	errors = c.CheckExpression(word);
	res = errors->Put();

	EXPECT_EQ(-1, res.GetPosition());
	EXPECT_EQ("Ошибка в скобках.", res.GetText());
	res = errors->Put();
	EXPECT_EQ(0, res.GetPosition());
	EXPECT_EQ("Ошибка в закрывающей скобке. Позиция ошибки: ", res.GetText());
}
TEST(Corrector, can_pass_correct_word) {
	Lexema *word = new Lexema[6];
	word[0] = Lexema(Type_Lexems::open_bracet, "(", 0);
	word[1] = Lexema(Type_Lexems::digit, "1", 1);
	word[2] = Lexema(Type_Lexems::add, "+", 2);
	word[3] = Lexema(Type_Lexems::digit, "2", 3);
	word[4] = Lexema(Type_Lexems::close_bracket, ")", 4);
	word[5] = Lexema(Type_Lexems::terminal, "", 5);
	Corrector c;
	Stack<Error>* errors;
	Error res;

	errors = c.CheckExpression(word);
	if (errors->IsEmpty())
	{
		res = Error(-2, "Ура, ошибок нет!");
	}
	else
	{
		res = errors->Put();
	}

	EXPECT_EQ(-2, res.GetPosition());
	EXPECT_EQ("Ура, ошибок нет!", res.GetText());
}