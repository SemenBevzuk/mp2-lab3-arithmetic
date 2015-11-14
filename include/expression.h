
class Expression {
public:
	virtual ~Expression() {}
	virtual double Calculate() = 0;
};

class Digit : public Expression{
public:
	Digit(double value) { Value = value; }
	double Calculate() override { return Value; };
private:
	double Value;
};

class Var : public Expression {
public:
	double Calculate() override { 
	    //TODO: Нужна проверка IsSet, и ввод значения из консоли
		return Value; 
	};
	Var() {}
	Var(double value)
	{
		Value = value;
		IsSet = true;
	};
	void SetValue(double x) { Value = x; };

private:
	double Value;
	bool IsSet = false;
};

class UnaryMinus : public Expression{
	Expression* expression;
public:
	void SetExpression(Expression* theExpression)
	{
		expression = theExpression;
	};
	double Calculate() override { return -expression->Calculate(); };
};

class BinaryOperation : public Expression {
public:
	void SetLeft(Expression* theLeft) { Left = theLeft; };
	void SetRight(Expression* theRight) { Right = theRight; };
protected:
	Expression* Left;
	Expression* Right;
};

class Multiply : public BinaryOperation
{
public:
	double Calculate() override { return Left->Calculate() * Right->Calculate(); };
};

class Divide : public BinaryOperation {
public:
	double Calculate() override { return Left->Calculate() / Right->Calculate(); };
};

class Add : public BinaryOperation {
public:
	double Calculate() override { return Left->Calculate() + Right->Calculate(); };
};

class Minus : public BinaryOperation {
public:
	double Calculate() override { return Left->Calculate() - Right->Calculate(); };
};