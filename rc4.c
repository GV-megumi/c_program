#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//s表的长度取256
#define size 256

unsigned char sbox[257]= {0};

//初始化s表
void init_sbox(int*key,int abc) {
    unsigned int i,j,k;
    int tmp;

    for(i=0; i<size; i++) {
        sbox[i]=i;
    }

    j=k=0;
    for(i=0; i<size; i++) {
        tmp=sbox[i];
        j=(j+tmp+key[k])%size;
        sbox[i]=sbox[j];
        sbox[j]=tmp;
        if(++k>=abc)k=0;
    }
}

//加解密函数
void enc_dec(int*key,unsigned char*data,int abc) {
    int i,j,k,R,tmp;

    init_sbox(key,abc);

    j=k=0;
    for(i=0; i<strlen((char*)data); i++) {
        j=(j+1)%size;
        k=(k+sbox[j])%size;

        tmp=sbox[j];
        sbox[j]=sbox[k];
        sbox[k]=tmp;

        R=sbox[(sbox[j]+sbox[k])%size];

        data[i]^=R;
    }
}

int main() {
    int key[100],i=0,k;
    unsigned char data[100]= {0};
    printf("输入密钥数k[?]:");
    scanf("%d",&k);
    printf("输入你要加密的字符：");
    scanf("%100s",data);

    printf("输入密钥k[%d]～k[%d]：",i,k-1);
    for(i; i<k; i++)
    {
        scanf("%d",&key[i]);

    }
    enc_dec(key,data,k);
    printf("enc: %s\n",data);
    enc_dec(key,data,k);
    printf("dec: %s\n",data);
    system("pause");
    return 0;
}

