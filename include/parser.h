#include <iostream>

using namespace std;

enum Type_Lexems { var, digit, binary_operation, unary_operetion, open_bracet, close_bracket };

class Lexema
{
private:
	Type_Lexems Type;
	string Value;
public:
	Lexema();
	Lexema(Type_Lexems type, string val);
	bool operator==(const Lexema &v) const;
	Type_Lexems GetTypeLexems() const { return Type; }
	string GetValue() const { return Value; }

	friend ostream& operator<<(ostream &out, const Lexema &l) {
		out << l.Type << endl;
		out << l.Value.c_str() << endl;
		return out;
	}
};

class Parser
{
private:
	void AddVariable(string var, Lexema* res, int index);
	void AddDigit(string var, Lexema* res, int index, int *for_index);
	void AddOperationBinary(string var, Lexema* res, int index);
	void AddOperationUnary(string var, Lexema* res, int index);
	void AddOpenBracket(string var, Lexema* res, int index);
	void AddCloseBracket(string var, Lexema* res, int index);

	bool IsVariable(string str, int index);
	bool IsDigit(string str, int index);
	bool IsOperationBinary(string str, int index);
	bool IsOperationUnary(string str, int index);
	bool IsOpenBracket(string str, int index);
	bool IsCloseBracket(string str, int index);
public:
	Lexema* Parse(string input);

};
