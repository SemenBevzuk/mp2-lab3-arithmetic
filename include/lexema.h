#include <iostream>
#include <sstream>

using namespace std;

enum Type_Lexems { var, digit, unary_operetion_minus, open_bracet, close_bracket, terminal, add, minus, multiply, divide };

class Lexema {
private:
	Type_Lexems Type;
	string Value;
	int Position;
	double Decimal;


public:
	Lexema();
	Lexema(Type_Lexems type, string val, int pos = -1);
	Lexema(Type_Lexems type, double dec);

	bool operator==(const Lexema &v) const;
	Type_Lexems GetType() const { return Type; }
	string GetValue() const { return Value; }
	double GetDecimalValue() const { return Decimal; }
	void SetPosition(int pos) { Position = pos; }
	void SetDecimal(double dec) { Decimal = dec; }
	int GetPosition() { return Position; }

	friend ostream& operator<<(ostream &out, const Lexema &l) {
		out << l.Type << endl;
		out << l.Value.c_str() << endl;
		return out;
	}
};