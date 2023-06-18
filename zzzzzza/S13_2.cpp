#include <iostream>
#include <string.h>
using namespace std;


//13


void fun1(char *s, int n, int r) // 将n转换为r进制，结果放在5所指向的数组中
{
    int i = 0, t;
    while (n) // 转换的算法是除取余，首先取出来的是低位数字，高位数字最后出来
    {
        t = n % r;   // 求余数
        if (t >= 10) // 余数有可能大于10（十六进制）

            // 1

            s[i++] = char(t + 55); // 大于10的数字转换成字符A~F

        // 2

        else
            s[i++] = char(t + 48); // 对于其余的数字，直接将数字变成字符的形式
        n = n / r;                 // n除r后继续取余转换，直到n为0为止
    }
    s[i] = '\0'; // A
}
void fun2(char *s)
// 由于上述转换算法转换出的结果低位在前，所以正确的结果应将字符串倒序排列
{
    char ch;
    int len = strlen(s); // 字符串的长度

    // 3

    for (int i = 0; i < len / 2; i++) // 将第1个字符和最后一个字符交换，第2个字符和倒数 第2个字符交换，直至交换到字符串的中间位置*/
    {
        ch = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = ch;
    }
}

int main()
{
    // 因为转换后的数有可能出现字母A～E，所以用字符串的形式存放
    char s[200];
    int n, r;

    cout << "请输人您想转换的十进制数：";
    cin >> n;
    cout << "你想将十进制数" << n << "转换成多少进制的数？ ";
    cin >> r;
    fun1(s, n, r); // 将n转换为r进制的数，结果存放在s中，转换的算法是除r取
    fun2(s);
    cout << "十进制数" << n << "转换成" << r << "进制的数，结果为：" << s <<"\n\n\n\n";
    
    
    system("pause");
    return 0;
}
