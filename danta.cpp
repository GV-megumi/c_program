// 蛋挞.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

/*
通达学院蛋挞店开业大促销。假设当前有且仅有N个顾客排队购买，并假设不再有新的顾客到来
。每个顾客最多限买M个，但必须排队依次购买。烘焙员每次烘焙出的一组蛋挞的个数依次为1个，
2个，…K个，每次烘焙完一组后，他将新烘焙的一组蛋挞放入盘中，此时排在队首的一个顾客才能购买
，且必须在下一组蛋挞放入盘中前购买完（初始情况下，盘中无蛋挞）。下一个顾客必须等到下一组蛋挞
烘焙完并放入盘中后，才能继续购买，以此类推。现在假设每个顾客都想买到全部的M个蛋挞，且若其一次购
买未达到M个，将重新排到队尾，等待下一次购买机会。而当烘焙员一次烘焙出的一组蛋挞的数量为K时，下次
烘焙出的一组蛋挞的个数又将回到1个，并重复上述烘焙过程。无论顾客分几次购买，一旦买到的蛋挞总数等于
M个，则离开队伍。假设顾客每次排队都希望买到最多数量的蛋挞以尽快达到总购买数为M的目标，且上述排队购
买过程将一直进行下去直到每个顾客都买到M个蛋挞为止。试根据M、K、N的不同值，输出每个顾客每次的购买情
况，并输出所有顾客完成购买的时间顺序。
*/

//

#include <iostream>
#include<vector>
using namespace std;

struct guke {
    vector<int> num;//每次购买的数量
    int danta;//已购买的总数
    int xuhao;//顾客n

    guke(int n):danta(0),xuhao(n){}
    guke():danta(0){}
    guke(const guke *p):num(p->num),danta(p->danta),xuhao(p->xuhao){}
};
//完成一次购买
int goumai(vector<guke>* g, vector<guke>* gq, int* dantashu, int m) {

    vector<guke>::iterator p = (*g).begin();
    vector<guke>::iterator p0;
    //在买
    int goumaishu;
    int yn;   //1不用排了0还要排
    if (m-p->danta>*dantashu) {//此处if条件若取到等于则可能会出现下一次顾客购买0个的情况
        goumaishu = *dantashu;
        *dantashu = 0;
        yn = 0;
    }
    else {
        goumaishu = m - p->danta;
        *dantashu -= goumaishu;
        yn = 1;

    }
    p->danta += goumaishu;
    p->num.push_back(goumaishu);

    //买完后判断还要不要继续排队
    if (yn == 0) {
        //排队
        (*g).push_back(*(*g).begin());        //队尾加
        (*g).erase((*g).begin());//队首删
        return -1;
    }
    else {
        int xuhao = (*g).begin()->xuhao;
        p0 = gq->begin()+xuhao-1;
        *p0 = *(*g).begin();

        (*g).erase((*g).begin());//队首删
        return xuhao;
    }
    

}

void putguke(vector<guke> gq) {
    vector<guke>::iterator g1;//顾客队列迭代器
    vector<int>::iterator p;
    int i;
    for (g1 = gq.begin(); g1 != gq.end(); g1++) {
        cout << "顾客" << g1->xuhao << ":   ";
        for (p = g1->num.begin(),i=1; p != g1->num.end(); p++, i++) {
            cout << "第" << i << "次购买数量：" <<"  "<< * p << "\t";
        }
        cout << endl;

    }
}

void putNo(vector<int> maiwan) {
    vector<int>::iterator m1;//完成购买的人的顺序迭代器
    for (m1 = maiwan.begin(); m1 != maiwan.end(); m1++)
        cout << *m1 << "  ";
}
int main()
{
    int n;//顾客数
    int dk=1,k;//每次做的蛋挞数dk，一次最多做k个
    int m;//每位顾客购买总数
    int dantashu=0;//当前做好的蛋挞数量
    vector<int> maiwan;//完成购买的人的顺序
    int i;
    int yn;//接收返回的顾客n
    vector<guke> g,gq;//顾客队列 g还在买，gq买完了
    n = 9;
    k = 5;
    m = 7;
    gq.resize(n);
    for (i = 1; i <= n; i++) {
        g.push_back(guke(i));
    }
   

    while(maiwan.size() != n) {
        ;
        if (dk > k)
            dk = 1;
        dantashu += dk;
        yn=goumai(&g,&gq, &dantashu,m);
        if (yn != -1) {
            maiwan.push_back(yn);
        }

        dk++;
    }


    putguke(gq);
    cout << endl;
    cout << "顺序：";
    putNo(maiwan);
    cout << endl;
    system("pause");
    return 0;

}

