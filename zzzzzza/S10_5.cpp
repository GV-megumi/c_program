#include <iostream>
using namespace std;

/*
   10

   给a，b，赋初值，获取a数组的数字数
遍历数组a 将a的个位与十位在b数组的对应位+1

输出b


*/
int main()
{

    int a[] = {5, 26, 98, 77, 1, 27, 30},
        b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        i;
    int n = sizeof(a) / sizeof(int); // 获取a的长
    for (i = 0; i < n; i++)
    {

        b[a[i] % 10]++; // 将个位对应的数+1
        if (a[i] / 10)  // 判断是否有十位
            b[a[i] / 10]++;
    }
    cout << "0~9依次出现:  ";
    for (i = 0; i < 10; i++)
        cout << b[i] << "  ";
    cout << "次\n";
    

    system("pause");
    return 0;
}
