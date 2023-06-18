#include <iostream>
using namespace std;
#include <string.h>

/*

2


    STR(char *str);
    构造函数，为S1,S2申请空间，将str的每个值赋值给s1
    不能s1=str，这样的话s1就指向了str所指的空间而不是申请的空间
    void delsame();
    删除方法：先令s2为空；
    遍历s1的每一个字符，判断它在s2中是否存在，若不存在则加到s2的末尾
    最后在s2末尾加入字符串结束符'\0'
    void show();
    输出字符串
    ~STR();
    删除 s1,s2,所申请空间

    主函数：申请一个STR空间，调用对应函数,最后删除该STR，会自动调用析构函数~STR（）

*/

class STR
{

private:
    char *s1, *s2;

public:
    STR(char *str);
    void delsame();
    void show();
    ~STR();
};

STR::STR(char *str)

{

    int n = sizeof(str);
    //申请空间
    s1 = new char[n];
    s2 = new char[n];
    for (int i = 0; i < n; i++)
        s1[i] = str[i];
}

void STR::delsame()
{
    int i, j, s2num = 0;
    bool notexit;//判断s1中某字符是否在s2中
    char c;
    for (i = 0; s1[i] != '\0'; i++)
    {
        notexit = true;
        for (j = 0; j < s2num; j++)
        {
            if (s1[i] == s2[j])
            {
                notexit = false;
                break;
            }
        }
//添加s2字符
        if (notexit)
        {
            s2[s2num++] = s1[i];
        }
    }
    s2[s2num] = '\0';
}
void STR::show()
{
    cout << "删除前的字符串：" << endl
         << s1 << endl;
    cout << "删除后的字符串：" << endl
         << s2 << endl;
}

STR::~STR()
{

    delete[] s1;
    delete[] s2;
    cout << "空间已释放" << endl;
}
int main()

{

    STR *test = new STR("concoon");
    test->delsame();
    test->show();

    delete test;

    system("pause");
    return 0;
}