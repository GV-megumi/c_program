#include<iostream>
using namespace std;
const int N=20 ;

int n=4; 
char a[4][4];
int l[N], //列
d[7],    //对角线
fd[7];   //反对角线

void dfs(int m){
int i,j;
if(m==n){
    for(i=0;i<4;i++){
for(j=0;j<4;j++)
cout<<a[i][j]<<" ";
cout<<endl;
}
cout<<endl;

return ;

}

for(i=0;i<n;i++)
{
if(l[i]&&d[i-m+n]&&fd[i+m])
{
a[m][i]='Q';
l[i]=d[i-m+n]=fd[i+m]=0;

dfs(m+1);

a[m][i]='-';
l[i]=d[i-m+n]=fd[i+m]=1;

}


}


}


int main(){
int i,j;


for(i=0;i<4;i++){
for(j=0;j<4;j++)
a[i][j]='-';
l[i]=1;
}

for(i=0;i<2*n-1;i++)
{
    d[i]=fd[i]=1;
}

dfs(0);


system("pause");
    return 0;
}