#include <iostream>
#include "Calculator.h"
using namespace std;

int main()
{
    double x = 0.0;
    double y = 0.0;
    double wynik = 0.0;
    char oper = '+';

    cout << "Kalkulator\n\n";
    cout << "Wpisz operacje do wykonania. format: a+b | a-b | a*b | a/b\n";

    Calculator calculator;
    while (true)
    {
        string input;
        cin >> input;
        if (oper == '/' && y == 0)
        {
            cout << "Nawet nie probuj\n";
            continue;
        }
        else
        {
            int length = size(input);
            for (int i = 0; i < length; i++)
            {
                if (!isdigit(input[i]))
                {
                    double answer = calculator.Calculate(x, oper, y);
                    cout << "Wynik to: " << answer << endl;
                }
                else
                {
                    cout << "Incorrect value, try again\n";
                    cin >> input;
                }
            }
        }
    }
    return 0;
}