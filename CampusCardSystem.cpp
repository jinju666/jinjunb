#include "card_operations.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    try
    {
        card::title("校园一卡通消费管理系统");

        int studentNum;
        cout << "请输入学生账户数量：";
        cin >> studentNum;

        Card* cardArr = createCards(studentNum);
        inputCards(cardArr, studentNum);

        cout << "\n===== 对第一个账户充值100元 =====" << endl;
        deposit(cardArr[0], 100.0);

        cout << "\n===== 对第一个账户消费8.5元（食堂午餐） =====" << endl;
        spend(cardArr[0], 8.5, "食堂午餐");

        cout << "\n===== 查询第一个账户信息 =====" << endl;
        showBalance(cardArr[0]);
        viewStudentID(&cardArr[0]);

        int cent = toCent(cardArr[0].balance);
        cout << "余额换算成分：" << cent << " 分" << endl;

        cout << "\n===== 全部账户报表 =====" << endl;
        printReport(cardArr, studentNum);

        destroyCards(cardArr);
    }
    catch (const runtime_error& e)
    {
        cout << "\n异常捕获：" << e.what() << endl;
    }

    cout << "\n系统结束" << endl;
    return 0;
}