#include <iostream>
using namespace std;

// 3

int sum(int b[3][4], int k) // 计算二维数组第k列的和
{
    int s = 0, i;

    for (i = 0; i < 3; i++)
        //(1)
        s += b[i][k];
    return s;
}
//(2)
void exch(int b[3][4], int x, int y) // 交换二维数组的x列和y列
{
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        a[i] = b[i][x];
        b[i][x] = b[i][y];
        b[i][y] = a[i];
    }
}

int main()
{
    int a[3][4] = {{5, 8, 10, 15}, {17, 6, 4, 8}, {6, 15, 9, 12}};
    int i, j, m, t[4];

    cout << "原始数组:\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
    //(3)
    for (i = 0; i < 4; i++)
        t[i] = sum(a, i);

    for (i = 0; i < 3; i++) // 用冒泡法对数组排序
        for (j = 0; j < i + 1; j++)
            if (t[j] > t[j + 1])
            {
                m = t[j];
                t[j] = t[j + 1];
                t[j + 1] = m;
                // 4
                exch(a, j, j + 1);
            }

    cout << "排序后的数组:\n";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
    system("pause");
    return 0;
}