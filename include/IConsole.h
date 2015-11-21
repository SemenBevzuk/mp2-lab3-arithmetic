#pragma once
#include <string>
#include <iostream>

class IConsole
{
public:
	virtual double GetValue(std::string name) = 0;
};

class Console : public IConsole
{
public:
	Console();
	double GetValue(std::string name) override {
		double d;
		std::cout << "Введите значение переменной  "<< name <<": ";
		std::cin >> d;
		std::cout << std::endl;
		return d;
	}
};

class ConsoleStub : public IConsole {
private:
	double value;
public:
	ConsoleStub(double d)
	{
		SetValue(d);
	}
	void SetValue(double d)
	{
		value = d;
	}
	double GetValue(std::string name) override {
		return value;
	}
};