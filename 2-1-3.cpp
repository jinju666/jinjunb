#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

inline double square(double x)
{
    return x * x;
}

double power(double base, int exponent = 2)
{
    double res = 1.0;
    for (int i = 0; i < exponent; i++)
    {
        res *= base;
    }
    return res;
}

double calc(double a, double b, char op)
{
    double ans = 0;
    if (op == '+') ans = a + b;
    else if (op == '-') ans = a - b;
    else if (op == '*') ans = a * b;
    else if (op == '/')
    {
        if (b == 0)
        {
            cout << "Error: divide by zero" << endl;
            return 0;
        }
        ans = a / b;
    }
    return ans;
}

int main()
{
    double a, b;
    char op;
    cout << "请输入两个操作数和运算符（如 3 5 +）：";
    cin >> a >> b >> op;

    cout << fixed << setprecision(2);
    cout << "square(" << a << ") = " << square(a) << endl;
    cout << "power(" << a << "," << b << ") = " << power(a, b) << endl;

    if (op == '/' && b == 0)
    {
        cout << "Error: divide by zero" << endl;
    }
    else
    {
        cout << a << " " << op << " " << b << " = " << calc(a, b, op) << endl;
    }

    system("pause");
    return 0;
}
