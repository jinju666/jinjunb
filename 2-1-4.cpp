#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x, y;
    cout << "请输入两个整数：";
    cin >> x >> y;
    cout << "交换前：x=" << x << ", y=" << y << endl;
    swap(x, y);
    cout << "交换后：x=" << x << ", y=" << y << endl;
    system("pause");
    return 0;
}
