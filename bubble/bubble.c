#include<stdio.h>
#include<stdlib.h>
#include"createfolder.h"
#include"bubble.h"

/*冒泡排序*/

void bubble(int *a,int n);
void print(int *a,int n);

int main(void)
{
   
    int a[10]={6,4,3,2,7,8,9,10,1,5};
    int i;
 bubble(a,10);
 print(a,10);
    system("pause");
 } 
