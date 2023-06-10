#include<stdio.h>
void bubble(int *a,int n){
    int w,k;
   for(int i=0;i<n-1;i++)
    {
        for(k=0;k<n-1-i;k++)
        {
            if(a[k]>a[k+1])
            {
                w=a[k];
                a[k]=a[k+1];
                a[k+1]=w;
            }
        }
    }

}
void print(int *a,int n){
   for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
