#include "lexema.h"


Lexema::Lexema() {
	Type = Type_Lexems::terminal;
	Value = "0";
	Position = -1;
};

Lexema::Lexema(Type_Lexems type, string val, int pos) {
	Type = type;
	Value = val;
	Position = pos;
	if (type == Type_Lexems::digit) { //2.8->2.0 â sample
		std::stringstream stream(val);
		stream >> Decimal;
		//Decimal = stod(val);
	}
}

Lexema::Lexema(Type_Lexems type, double dec) {
	Type = type;
	Decimal = dec;
}

bool Lexema::operator==(const Lexema &v) const {
	if (Type != v.Type) {
		return false;
	}
	if (Value.length() != v.Value.length()) {
		return false;
	}

	for (int i = 0; i < Value.length(); i++) {
		if (Value[i] != v.Value[i]) {
			return false;
		}
	}
	return true;
}