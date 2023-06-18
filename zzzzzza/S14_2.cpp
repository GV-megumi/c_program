

//   6  14

#include <iostream>
using namespace std;
class NUM
{ // 定义数据类 NUM
private:
    int n;
    int *p;

public:
    NUM(int n1)
    // 构造函数，用n1初始化n，并且用p动态开辟n个整数空间，用来存放符合条件的合数
    {
        n = n1;

        // 1

        p = new int[n]; // 连续开辟n个整型空间，将整型空间的首地址赋给p
    }
    int yes(int x) // 判断x是否为合数，若是则返回 1，否则返回
    {
        for (int i = 2; i <= x / 2; i++) // i从2循环到x/2，依次判断x能否整除i
            if (x % i == 0)              // 若能整除，说明x是合数
                return 1;                // 直接返回1
        return 0;                        // 循环结束，说明不能整除，不是合数，返回0
    }
    void fun() // 寻找 n个连续的合数
    {
        int j;
        for (int i = 3; 1; i++) // 从3开始向上找，因为未给上限，所以一直循环
        //(循环条件永远满足)
        {
            j = 0;
            // 对连续的合数计数，所以在每次找之清零

            // 2

            while (yes(i) &&j < n) // 当前的数i是合数且没有找到连续n个时，循环向后寻找

            {
                
                p[j] = i; // 边找边将合数赋给动态开辟的数组空间,赋完值后序号加1
                j++;
                i++; // 继续判断下一个连续的数是否满足条件
            }
            if (j == n) // 当找到n个连续的合数时，退出上面的while循环
                break;  // 操作完成，用break强制退出for循环
        }
    }
    void print() // 输出满足条件的连续的合数
    {
        for (int i = 0; i < n; i++)
            cout << p[i] << '\t';
        cout << endl;
    }
    ~NUM() // 析构函数，释放在构造函数中动态开辟的数组空间
    {
        if (p)
            delete[] p;
    }
};
int main()
{
    NUM num(10); // 定义类的对象，并调用构造函数动态开辟10个整型空间

    // 3

    num.fun(); // 对这个对象完成寻找连续的合数的操作，并把操作结果存放在动态开辟的空间中

    // 4

    num.print(); // 调用对象的成员函数，输出连续的合数
    system("pause");
    return 0;
} // 函数结束，对象num的作用域也结束，调用析构函数释放对象所占用的空间
