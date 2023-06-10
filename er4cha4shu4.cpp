
#include <iostream>
using namespace std;
typedef char elem;
//二叉树

//接点
typedef struct btn {
    elem e;
    struct btn* lc,//左
        *rc;//右

};
//shu
typedef struct btr {
    btn* root;
};
//建空树
void create(btr* bt) {
    bt->root = NULL;

}



//先序构造
btn* gouzao(btn *t) {
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;

    else {

        t = (btn*)malloc(sizeof(btn));
        t->e = ch;
        t->lc = gouzao(t->lc);
        t->rc = gouzao(t->rc);
    }
    return t;
}
//先序遍历
void xianxu(btn* t) {
    if (!t)
        return;
    cout << t->e;
    xianxu(t->lc);
    xianxu(t->rc);
}
//中
void zhongxu(btn* t) {
    if (!t)
        return;
    zhongxu(t->lc);
    cout << t->e;
    zhongxu(t->rc);
}
//后
void houxu(btn* t) {
    if (!t)
        return;
    houxu(t->lc);
    houxu(t->rc);
    cout << t->e ;
}
//高度
int high(btn* t) {
    int h1,h2;
    if (!t)
        return 0;
    else {
        h1 = high(t->lc) + 1;
        h2 = high(t->rc) + 1;

    }
    return h1 > h2 ? h1 : h2;
}
//节点数
int size(btn* t) {
  
    if (!t)
        return 0;
    else
        return size(t->lc) + size(t->rc) + 1;
}
//叶子数
int leaves(btn* t) {
    if (!t)
        return 0;
    if (!(t->lc && t->rc)) {
        //cout << endl << "_________________________" << t->e;
        return 1;
    }

    else {
       // cout << endl << "-----------------------" << t->e;
        return leaves(t->lc) + leaves(t->rc);
    }
}
//交换左右子树
void jiaohuan(btn* bt) {
    btn* btt = bt->rc;
    bt->rc = bt->lc;
    bt->lc = btt;
    if (bt->lc)
        jiaohuan(bt->lc);
    if (bt->rc)
        jiaohuan(bt->rc);

}

int main()
{

    btr bt;
    create(&bt);
    bt.root=gouzao(bt.root);
    //ADEH##FJ##G###B#CK###
    cout << "先序序列：";
    xianxu(bt.root);
    cout << endl<<"中序序列：";
    zhongxu(bt.root);
    cout << endl<<"后序序列：";
    houxu(bt.root);
    cout << endl;
    cout <<"高度："<< high(bt.root) << endl <<"结点数："<< size(bt.root) << endl;
    cout <<"叶子结点数："<< leaves(bt.root);
    cout << endl << "========================" << endl<<"交换左右子树后："<<endl;
    jiaohuan(bt.root);

    cout << "先序序列：";
    xianxu(bt.root);
    cout << endl << "中序序列：";
    zhongxu(bt.root);
    cout << endl;
}
