#include <iostream>
using namespace std;
#include <string.h>

/*

8
始让n=0
遍历字符串a，对每个字符，若为字母，则n++；
否则判断n与b的长，若长则将a中的i-n~i-1段字符赋值给b

最后输出b


*/

int main()
{
    string a =
        "Apple$12pear watermelon $   # Banana"; // 获取字符串
    string b = "";                            // 储存最长的字符串
    int i, j, n = 0;
    for (i = 0; i <= a.length(); i++) // a.length获取字符串长
    {
        // 记录一个英文字符串的长
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) // 判断单个字符是否在a~z，A~Z内
            n++;
        else
        {
            if (n < b.length() || (b = a.substr(i - n, n)) == "") // 比较n的长和当前b字符串的长，若长则将新串赋给b
                ;
            n = 0;
           
        }
    }
    // 循环结束，输出b
    cout <<"字符串：\t"<<a<<"\t中最长的字母子串为：\n"<< b << endl;
    system("pause");
    return 0;
}
