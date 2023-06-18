

//9

#include<iostream>
#include<string> 
using namespace std; 
int main()
{ 
    char str[100];	//定义存放字符串的数组空间	
int flag=0;	//状态变量，辅助判断用	
cout <<" Input a string:\n";
cin.getline(str,100);	//从键盘输入字符串

//1


for(int i=0;str[i]!='\0';i++)	//从字符串首地址依次扫描字符串直至'\0	

//2


{ if(str[i]>='a'&&str[i]<='z'&&!flag) //当前字符为小写字符且flag为0

//3


{str[i]=str[i]-32;	//将小写字符变成大写字符	
flag=1;/*将flag置为1，下一个小写字符就不会满足if条件，不转换成大
写，这样保证一个单词只有第1个字符转换成大写*/
}
if(str[i]==' '||str[i]=='\n')

//4


flag=0;/*当前字符为空格时，将flag置为0，这样当遇到下一个字
符时,又满足上面的if条件而转换成大写字符*/
}
cout<<"the result is:\n";
cout << str << endl;	//输出结果	
system("pause");
return 0;}
