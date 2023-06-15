#include <iostream>
using namespace std;

/*

1



void print(int* p)
输出a数组里所有的数，由题可知数组里所有的数都小于256，
所以加一个判断p[i]<256&&p[i]>=0，原因是后面要减去一个
最大值会使数组a出现一个空值(-1414812757),所以去掉这个空值
void init(int* p)
初始化数组，用循环按题目要求给数组赋值
double ave(int *p)
求平均数，用循环将数组内的值全部加到sum中，
函数返回sum/16（平均值）
void del(int *p)
删除最大值，
首先找到最大值：先调用ave（）求出平均值
令max=0
然后用循环判断数组中的每一个值与平均值的差的绝对值是否比max与平均值的
差的绝对值大，如果大则将该值赋给max并记录该值的位置
最后从最大值所在位置开始，向后遍历数组，将后一个值赋值给当前值，覆盖掉最大值

调用print（）输出数组
*/

// 输出数组
void print(int *p)
{

    int i;
    for (i = 0; i < 16; i++)
        if (p[i] < 256 && p[i] >= 0)
            cout << p[i] << " ";
    cout << endl;
}

// 给数组a赋值，循环15次用要求的式子赋值
void init(int *p)
{
    int i;
    for (i = 1; i < 16; i++)
        p[i] = (15 * p[i - 1] + 97) % 256;
}

// 求平均数
double ave(int *p)
{
    int i;
    double sum = 0;

    for (i = 0; i < 16; i++)
    {
        sum += p[i];
    }
    return sum / 16;
}

// 删除最大的数
void del(int *p)
{

    int i, max = 0, maxi;

    int avenum = ave(p);

    for (i = 0; i < 16; i++)
    {
        if (abs(avenum - max) < abs(avenum - p[i]))
        {
            max = p[i];
            maxi = i;
        }
    }
    cout << "最大值 = " << max << endl;

    for (i = maxi; i < 16; i++)
        p[i] = p[i + 1];
    cout << "删除" << max << "后的数组元素：" << endl;
    print(p);
}

int main()
{
    int *a = (int *)malloc(16 * sizeof(int)); // 申请16个整形空间

    a[0] = 55;

    init(a);
    cout << "a数组元素为：" << endl;
    print(a);

    cout << "平均值=" << ave(a) << endl;

    del(a);

    cout << endl
         << endl;

    free(a);

    system("pause");
    return 0;
}