

//   7  15
#include <iostream>
using namespace std;
class NUM
{
    int n, count;
    int *p;

public:
    NUM(int num)
    {
        n = num;
        p = new int[n + 1];
        for (int i = 1; i <= n; i++)
            *(p + i) = 0;
        count = n;
    }

    int d(int num) // 函数的返回值不是自身数
    {
        int t = num;
        while (num)
        {

            //   1


            t = t+num%10;
            num = num / 10;
        }
        return t;
    }

    void fun()
    {
        int t;
        for (int i = 1; i <= n; i++) // i为发生器,计算所有的非自身数
        {

            //2


            t = d(i); // t不是自身数
            if (t <= n && p[t] == 0)
            {
                p[t] = 1; // 不是自身数,进行标记

                //3


                count = count-1;
            }
        }
    }
    void print()
    {
        cout << "不大于" << n << "的自身数有" << count << "个: \n";
        for (int i = 1; i <= n; i++)

        //4


            if (!p[i])
                cout << i << '\t'; // 输出所有的自身数
    }
    ~NUM()
    {
        if (p)
            delete[] p;
    }
};

int main()
{
    int x;
    cout << "请输人一个正整数:";
    cin >> x;
    NUM num(x);
    num.fun();
    num.print();
    cout<<endl;
    system("pause");
    return 0;
}
