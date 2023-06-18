
// 5

#include <iostream>
#include <cmath>
using namespace std;
class Tri
{
    double a, b, c; // 定义三角形的三边
public:
    Tri(double x, double y, double z) // 构造函数,初始化三边
    {
        a = x;
        b = y;
        c = z;
    }
    double Peri() // 返回三角形的周长
    {
        return (a + b + c);
    }
    double Area() // 返回三角形的面积
    {
        double s = Peri() / 2;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        return area;
    }
    void Show() // 输出三角形的参数
    {
        cout << " 三角形的边长 :" << a << '\t' << b << '\t' << c << endl;
        cout << "三角形的周长:" << Peri() << endl;
        cout << "三角形的面积:" << Area() << endl
             << endl;
    }
}; // 三角形类的定义结束，定义了三角形的各种属性和可实施的操作
// main函数决定了程序运行的过程和顺序
int main()
{
    Tri tri1(3, 4, 5), tri2(5, 6, 7); // 定义了两个具体的三角形

    // 输出这两个三角形的参数
    tri1.Show();
    tri2.Show();
    system("pause");

    return 0;
}
