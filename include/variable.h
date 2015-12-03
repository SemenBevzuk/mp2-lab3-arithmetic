#pragma once

class Variable {
private:
	double Value = 0;
	bool Set = false;
	std::string Name = "";
public:
	Variable() {
		Set = false;
		Name = "";
	}
	Variable(std::string name) {
		Set = false;
		Name = name;
	}
	Variable(std::string name, double d) {
		Set = true;
		Name = name;
		Value = d;
	}

	void SetVariable(double val)
	{
		Value = val;
		Set = true;
	}
	double GetValue() { return Value; }
	bool IsSet() { return Set; }
	std::string GetName() { return Name; }
};