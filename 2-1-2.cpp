#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int countVowels(const char* p)
{
    int cnt = 0;
    while (*p != '\0')
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u'
            || *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U')
        {
            cnt++;
        }
        p++;
    }
    return cnt;
}

int main()
{
    char str[1000];
    cout << "请输入一行字符串：";
    cin.getline(str, 1000);
    int res = countVowels(str);
    cout << "元音字母的数量：" << res << endl;
    system("pause");
    return 0;
}
