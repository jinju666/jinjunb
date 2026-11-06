#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct Student
{
    string name;
    double chinese, math, english;
};

int main()
{
    int n;
    cout << "请输入学生人数：";
    cin >> n;
    Student s;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; ++i)
    {
        cout << "请输入第" << i + 1 << "名学生信息（姓名 语文 数学 英语）：";
        cin >> s.name >> s.chinese >> s.math >> s.english;
        double avg = (s.chinese + s.math + s.english) / 3.0;
        cout << left << setw(10) << s.name
            << setw(8) << s.chinese
            << setw(8) << s.math
            << setw(8) << s.english
            << setw(8) << avg;
        if (avg >= 90)
        {
            cout << " Excellent";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
