#include <math.h> // Vova: imports math  related functions
#include <emscripten.h> // Vova: lets emsdk compile the file. The red underline is okay

EMSCRIPTEN_KEEPALIVE
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
	case '^': // Vova: I just wanted to put one number to the power of the other y'all
		return pow(x,y);
	default:
		return 0.0;
	}
}
