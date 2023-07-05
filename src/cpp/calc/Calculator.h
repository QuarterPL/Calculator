// #pragma once
#define CALCULATOR_H
class Calculator
{
public:
	Calculator() {}
	double calculate(double x, char oper, double y)
	{
		switch (oper)
		{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		default:
			return 0.0;
		}
	}
};
