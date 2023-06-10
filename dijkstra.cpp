
#include <iostream>
using namespace std;
#include<vector>
#define NS 9999999    //无通路时的值


typedef struct mgr {
    int** a;
    int n; //顶点数
    int e;//边数
};
//邻接矩阵初始化
int init(mgr *m,int n) {
    int i, j;
    m->n = n;
    m->e = 0;
    m->a=(int**)malloc(n * sizeof(int*));
    if (!m->a)
        return 0;
    for (i = 0; i < m->n; i++) {
        m->a[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < m->n; j++)
            m->a[i][j] = NS;
        m->a[i][i] = 0;
    }
    return 0;
}
//邻接撤销
void destory(mgr *m){
    for (int i = 0; i < m->n; i++) {

        free(m->a[i]);
    }
    free(m->a);
}
//边插入
int insert(mgr* m, int u, int v, int e) {
    //uv为无效边或已存在返回0
    if (u<0 || v<0 || u>m->n-1 || v>m->n-1 || u == v||m->a[u][v]!=NS)
        return 0;
    m->a[u][v] = e;
    m->e++;
    return 1;

}
//边删
int remove(mgr* m, int u, int v) {
    if (u<0 || v<0 || u>m->n-1 || v>m->n-1 || u == v || m->a[u][v] == NS)
        return 0;
    m->a[u][v] = NS;
    m->e--;
    return 0;

}
//初始化
void chushihua(mgr* m) {
    int i,j,a[6][6] = {
        {0,50,10,NS,80,NS},
        {NS,0,15,NS,20,NS},
        {NS,NS,0,15,NS,NS},
        {NS,20,NS,0,45,NS},
        {NS,NS,NS,NS,NS,NS},
        {NS,NS,NS,9,10,0}
    };

    init(m, 6);
    for (i = 0; i < 6; i++) 
        for (j = 0; j < 6; j++) {
            if(!(a[i][j]==NS))
            insert(m, i, j, a[i][j]);
        }

}

//选出最小的d[i] 返回下标
int choose(int* d, int* s, int n) {
    int i, minpos=-1, min=NS;
    for (i = 0; i < n; i++) {
        if (!s[i] && d[i] < min) {
            min = d[i];
            minpos = i;
        }

    }
    return minpos;
}

/*
迪某算法
v：顶点
path：数组，记录最短路径点
d:数组，记录顶点到点i最短路径距离
s：数组，记录点i的最短路径是否已被找到  1是0否
*/

int dij(int v,int *d,int *path,mgr g){
    int i, j,
        k;//下一个加入点的下标
    int* s;//记录i点是否已有最短路径






    if (v<0 || v>g.n - 1) {
        cout << "xxxxx";
        return 0;
    }
    s = (int*)malloc(g.n * sizeof(int));
    for (i = 0; i < g.n; i++) {
        s[i] = 0;
        d[i] = g.a[v][i];
        if (i != v && d[i] <NS)
            path[i] = v;
        else
            path[i] = -1;
    }
    s[v] = 1;
    d[v] = 0;
    //cout << v << "  ";
    for (i = 1; i < g.n -1; i++) {
        k = choose(d, s, g.n);
        if (k == -1)//
            continue;
     
        s[k] = 1;//k放到s集合里
       //cout << k<<"  ";
        for (j = 0; j < g.n; j++) {
            if (!s[j] && d[k] + g.a[k][j] < d[j])//j点不在s内且存在一条边使得此边加前面小于原来
            {
                d[j] = d[k] + g.a[k][j];
                path[j] = k;

            }
        }
            int zx = v;

            cout << v << "->" << k << "： min=" << d[k] << "      way：";
            int asd = k;
            vector<int> zxc;
            vector<int>::iterator zxcv;
            while (asd != v) {
                
                zxc.insert(zxc.begin(),asd);
                asd = path[asd];

            }                 
            zxc.insert(zxc.begin(), asd);
            for (zxcv = zxc.begin(); zxcv!=zxc.end(); zxcv++)
                cout << *zxcv<< "  ";
            cout << endl;

    }

}
//佛洛依德
void floyd(mgr g) {
    int i, j, k,**d,**p;
    vector<int> pw;
    vector<int>::iterator q;
    d = (int**)malloc(g.n * sizeof(int*)); //d数组，记录u-》v最短距离
    p = (int**)malloc(g.n * sizeof(int*));//p，记录u->v路径
    for (i = 0; i < g.n; i++) {
        d[i] = (int*)malloc(g.n * sizeof(int));
        p[i] = (int*)malloc(g.n * sizeof(int));
        for (j = 0; j < g.n; j++) {
            d[i][j] = NS;
            p[i][j]= 0;
        }
    }
    //初始化d,p
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            d[i][j] = g.a[i][j];

            if (i != j && d[i][j] < NS)
                p[i][j] = i;
            else
                p[i][j] = -1;
        }
    }
    //更新d，p
    for(k=0;k<g.n;k++)
        for(i=0;i<g.n;i++)
            for (j = 0; j < g.n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }

    //输出
    
    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            if (j == i||d[i][j]==NS)
                continue;
            cout << i << "->" << j << ":  min=" << d[i][j] << "  way:";
                k = p[i][j];
                pw.insert(pw.begin(), j);
                while (k != i) {
                    pw.insert(pw.begin(),k);
                    k = p[i][k];

                }
                pw.insert(pw.begin(), k);
                for (q = pw.begin(); q != pw.end(); q++)
                    cout << *q << "   ";
                cout << endl;
                pw.clear();
        }
    }

}

void putmgr(mgr m) {
    int i, j;
    for (i = 0; i < m.n; i++) {
        for (j = 0; j < m.n; j++) {
            if (m.a[i][j] != NS)
                cout << m.a[i][j] << "  ";
            else
                cout << "∞" << "  ";
        }
        cout << endl;

    }
    cout << endl;
}


int main()
{
    mgr m;
    int* d, * p,i,j;


    chushihua(&m);//初始化
    putmgr(m);
    d = (int*)malloc(m.n * sizeof(int));//记录v点到i点的最短路径长
    p = (int*)malloc(m.n * sizeof(int));//记录最短路劲上的点的前一个，例：0《-2,《-3；p[3]=2
    cout << "迪：" << endl;
    for (i = 0; i < m.n; i++) {
        dij(i, d, p, m);

    }
    cout << endl << endl<<"佛"<<endl;
    floyd(m);

    system("pause");
    return 0;
}

