#include <iostream>
using namespace std;


//  4


int main()
{
    int a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int i, j, t;
    cout << "转置前的数组a:\n";
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            cout << a[i][j] << '\t';
        cout << '\n';
    }

    for (i = 0; i < 4; i++)

    //       (1)

        for (j = 0; j<i; j++)// 遍历对角线下方的元素进行交换
            {
                t = a[j][i];

                //2

                a[j][i] = a[i][j]; // 行列互换

                //3

                a[i][j] = t;
            }
    cout << "转置后的数组a:\n";
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            cout << a[i][j] << '\t';
        cout << '\n';
    }
    system("pause");
    return 0;
}
