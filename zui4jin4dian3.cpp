#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
#define NS 999999999


/*
最近点对问题
一、课题内容和要求
    在二维平面上输入n个点列P。其中任一点pi=（xi，yi），编写程序求出最近的两个点。
1、先以蛮干法实现，算法复杂度O(n2)
2、优化算法，以O(nlog2n)实现这一问题，分析该算法的思想来源。
3、程序运行界面友好
4、思考该算法可以解决哪些实际问题，将思考结果写入实验报告中。
*/

struct point {
    double x, y;
    point(double a,double b):x(a),y(b){}
    point():x(NS),y(NS) {};
    void operator=( point a) {
        x = a.x;
        y = a.y;
    }
};

//获取pn点并按x从大到小排序
int paixu(vector<point>* q) {

    vector<point> p;
    int  j = 9,dx,dy;
    /*
    int dx[10] = { 12,15,2,37,92,17,4,9,7,10 };
    int dy[10] = { 13,16,2,8,6,18,93,18,16,0 };
    p.push_back(point(dx[i], dy[i]));
    */
    cout << "点数：" << endl;
    f1:cin >> j;
    if (j <= 1) {
        cout << "错误，请输入大于1的数:" << endl;
        goto f1;
    }
    j--;
    cout << "点的横纵坐标：" << endl;
    cin >> dx >> dy;
    p.push_back(point(dx, dy));
    vector<point>::iterator a, b;
    while (j != 0) {
       
        cin >> dx >> dy;

        for (a = p.begin(); a != p.end(); a++) {
            
            if (dx == a->x && dy == a->y) {
                cout << "该点已存在，请重新输入：";
                j++;
                break;
            }
            //尾插
            if (dx>= (p.end()-1)->x)
            {
                p.push_back(point(dx, dy));
                break;
            }
            //首查
            if (dx <=p.begin()->x) {
                p.insert(p.begin(), point(dx, dy));
                break;
            }
            b = a + 1;
            if (dx >= a->x && dx < b->x) {//a取等b不取用于辅助判断点是否重复
                p.insert(b, point(dx, dy));
                break;
            }


        }
        j--;

    }
    *q = p;
    return 1;
}
//计算两点间距离
double len(const point a,const point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
//蛮解法计算最短距离
double manjiefa(vector<point> p,point duan[]) {
    vector<point>::iterator a, b;
    double length = len(*p.begin(), *(p.begin() + 1));
    duan[0] = *p.begin();
    duan[1] = *(p.begin() + 1);
    for (a = p.begin(); a != p.end()-1; a++) {
        for (b = a + 1; b != p.end(); b++) {
           
            if (length > len(*a, *b)) {
                length = len(*a, *b);
                duan[0] = *a;
                duan[1] = *b;
            }

        }


    }

    return length;
}
//优化后计算最短距离
double youhua(vector<point> p, point duan[]) {
    vector<point>::iterator a, b;

    double x1, y1, y2;
    double length = len(*p.begin(), *(p.begin() + 1));
    duan[0] = *p.begin();
    duan[1] = *(p.begin() + 1);
    for (a = p.begin() + 2; a != p.end(); a++) {
        for (b = a - 1; b >= p.begin(); b--) {
            ;
            x1 = a->x - length;
            y1 = a->y - length;
            y2 = a->y + length;

            if (b->x < x1)
                break;
            else
            {
                if (b->y > y1 && b->y < y2 && length > len(*a, *b))
                {
                    length = len(*a, *b);
                    duan[0] = *b;
                    duan[1] = *a;
                }
            }
            //执行b--操作时b为-1时程序会意外停止
            if (b == p.begin())
                break;
        }

    }
    return length;
}


double fenzhi(vector<point> p, point duan[]) {
    int sl,  //左分支含有sl个点
        sr,  //同上
        i,j
        ;
    point duanl[2], duanr[2];//左右最短距离点
    double lmin=NS, rmin=NS, min;

    vector<point> lp, rp;//左右分支
    vector<point>::iterator q,qw;//迭代器

    sl = p.size() / 2;
    sr = p.size() - sl;
    //左分支点集
    lp = p;
    lp.resize(sl);
    //右
    for (q = p.begin() + sl; q != p.end(); q++) {
        rp.push_back(*q);
    }
    //>3     递归
    if (sl > 3) {
        lmin = fenzhi(lp, duanl);
    }
    if (sr > 3) {

        rmin = fenzhi(rp, duanr);
    }
    //点集内只有一个点-》长度取无穷
    if (sl < 2) {
        lmin = NS;
        duanl[0].x = p.begin()->x;
        duanl[0].y = p.begin()->y;
        duanl[1].x = NS;
        duanl[1].y = NS;
   }
    //点集内 有2-3个点--》蛮解法求最短
    if(sl==2||sl==3) {
        lmin=manjiefa(lp, duanl);

    }
    //同
    if (sr < 2) {
        rmin = NS;
        duanr[0].x = (p.begin()+sl)->x;
        duanr[0].y = (p.begin()+sl)->y;
        duanr[1].x = NS;
        duanr[1].y = NS;
    }
    //同
   if(sr==2||sr==3){
        rmin = manjiefa(rp, duanr);
    }

   //取左右最小长度
    if (lmin > rmin) {
        min = rmin;
        duan[0] = duanr[0];
        duan[1] = duanr[1];
    }
    else {
        min = lmin;
        duan[0] = duanl[0];
        duan[1] = duanl[1];

    }





    //左右联合比较
    for (q = lp.end() - 1, i = 0; i < 3 && q != lp.begin() ; q--, i++) //对左边靠近左右分割线的n（《=3）个点
    {
        for (qw = rp.begin(), j = 0; j < 3&&qw!=rp.end(); j++, qw++)//与右边靠近左右分割线的n（《=3）个点
        {
            if (q->x + min < qw->x|| qw->y > q->y + min || qw->y < q->y - min)//x2-x1>min   y上-y>min   //判断是否在[x,x+min][y-min,y+min]内
                continue;
            else 
            {
                if (len(*q, *qw) < min)//比较长短
                {
                    min = len(*q, *qw);
                    duan[0] = *q;
                    duan[1] = *qw;

                }
            }

        }

    }

   /* for (int t = 0; t < 2; t++)
        cout << "(" << duan[t].x << "," << duan[t].y << ")" << "    ";
    cout << endl;

    */

    return min;
}







int main()
{
    vector<point> p;//点集
    paixu(&p);//按x从小到大排序
    point duan[2],
        duann[2],
        duannn[2];//最短两点,分三个判断传值传址
    vector<point>::iterator a;


    // 10 12 13 76 86 1 2 98 76 5 23 7 8 89 76 -5 -4 98 0 1 23
    //输出所有点
    int jishu = 0;
    cout << "所有点为：" << endl;
    for (a = p.begin(); a != p.end(); a++) {
        cout << "(" << a->x << "," << a->y << ")" <<"\t"<<"\t";
        jishu++;
        if (jishu == 3) {
            jishu = 0;
            cout << endl;
        }
    }
    cout << endl << endl << endl << endl << endl;

     


    cout << "蛮解法求得：" << endl;
    cout << "最短距离：" << manjiefa(p, duan) << endl;
    cout << "对应的两点：";
    for (int t = 0; t < 2; t++)
        cout <<"("<< duan[t].x << "," << duan[t].y <<")" <<"    ";
    cout << endl << endl << endl;;




    
    cout << "优化后解法求得：" << endl;
    cout << "最短距离：" << youhua(p, duann) << endl;
    cout << "对应的两点：";
    for (int t = 0; t < 2; t++)
        cout << "(" << duann[t].x << "," << duann[t].y << ")" << "    ";
    cout << endl;
    



    cout << endl << endl << "分制法求得：" << endl;
    cout << "最短距离：" << fenzhi(p, duannn);
    cout <<endl<< "对应的两点：";
    for (int t = 0; t < 2; t++)
        cout << "(" << duannn[t].x << "," << duannn[t].y << ")" << "    ";
    cout << endl;
    system("pause");
    return 0;

}

