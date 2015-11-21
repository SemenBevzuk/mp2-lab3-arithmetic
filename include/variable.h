#pragma once

class Variable {
private:
	double Value = 0;
	bool Set = false;
	std::string Name = "";
public:

	Variable(std::string name) {
		Set = false;
		Name = name;
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