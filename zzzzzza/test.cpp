#include <iostream>
#include <cstdlib>
#include <fstream>
#include<direct.h>
#include<io.h>
#include <string>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void test1()
{
    for (int i = 2; i <= 10000; ++i)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

void test2()
{
    int year, num = 0;
    for (year = 401; year <= 2800; ++year)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            num++;
        }
    }

    cout << "从公元401年到2800年之间的闰年个数：" << num << " 个" << endl;
}

void test3()
{
    int second;

    cout << "请输入定时关机的时间（秒）：";
    cin >> second;

    if (second <= 0)
    {
        cout << "时间无效。" << endl;
        return;
    }

    // 构造关机命令
    string shutdownCommand = "shutdown -s -t " + to_string(second);

    // 执行关机命令
    int result = system(shutdownCommand.c_str());

    if (result == 0)
    {
        cout << "定时关机已启动。" << endl;
    }
    else
    {
        cout << "定时关机启动失败。" << endl;
    }
}


void createfolder(const char *p) {
	for (int i = 0; p[i] != '\0'; i++) {
		int j;
		char z[100];
		if (p[i] == '\\') {
			j = i - 1;
			int m;
			for (m = 0; m <= j; m++) {
				z[m] = p[m];
			}
			z[m] = '\0';
			if (_access(z, 0) == -1)
				_mkdir(z);
		}

	}
	if (_access(p, 0) == -1)
		_mkdir(p);


}






int main()
{

    cout << "test1" << endl;
    test1();
    cout << "test2" << endl;
    test2();
    cout << "test3" << endl;
    // test3();

    return 0;
}
