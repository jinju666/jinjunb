#include "card_operations.h"
#include <stdexcept>

namespace card
{
    void printLine(char c, int len)
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    void title(const std::string& s)
    {
        printLine('=');
        std::cout << std::setw((60 + s.size()) / 2) << s << std::endl;
        printLine('=');
    }
}

Card* createCards(int n)
{
    if (n <= 0)
    {
        throw std::runtime_error("账户数量不能小于等于0！");
    }
    Card* p = new Card[n];
    return p;
}

void destroyCards(Card* p)
{
    delete[] p;
}

void inputCards(Card* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "请输入第" << i + 1 << "个账户：学号 姓名 初始余额：";
        std::cin >> arr[i].id >> arr[i].name >> arr[i].balance;
        arr[i].transactions = 0;

        if (arr[i].balance < 0)
        {
            throw std::runtime_error("初始余额不能为负数！");
        }
    }
}

void deposit(Card& c, double amount, double fee)
{
    if (amount < 0)
    {
        throw std::runtime_error("充值金额不能为负数！");
    }
    double feeMoney = amount * fee;
    c.balance = c.balance + amount - feeMoney;
    c.transactions++;
}

bool spend(Card& c, double cost)
{
    if (cost < 0)
    {
        throw std::runtime_error("消费金额不能为负数！");
    }
    if (c.balance >= cost)
    {
        c.balance -= cost;
        c.transactions++;
        return true;
    }
    else
    {
        throw std::runtime_error("余额不足，消费失败！");
    }
}

bool spend(Card& c, double cost, const std::string& item)
{
    std::cout << "消费项目：" << item << std::endl;
    return spend(c, cost);
}

void showBalance(const Card& c)
{
    std::cout << "【常引用查询】学号" << c.id << " " << c.name << " 当前余额："
        << std::fixed << std::setprecision(2) << c.balance << " 元" << std::endl;
}

void viewStudentID(const Card* p)
{
    std::cout << "【常指针查询】账户学号：" << p->id << std::endl;
}

int toCent(double amount)
{
    return static_cast<int>(amount * 100);
}

void printReport(const Card* arr, int n)
{
    card::printLine();
    std::cout << std::left
        << std::setw(10) << "ID"
        << std::setw(12) << "Name"
        << std::setw(14) << "Balance(yuan)"
        << std::setw(14) << "Transactions"
        << std::endl;
    card::printLine();
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; i++)
    {
        std::cout << std::left
            << std::setw(10) << arr[i].id
            << std::setw(12) << arr[i].name
            << std::setw(14) << arr[i].balance
            << std::setw(14) << arr[i].transactions
            << std::endl;
    }
    card::printLine();
}