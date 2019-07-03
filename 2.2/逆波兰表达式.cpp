#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#define no -999999999
using namespace std;
char k[1001];
char s[1001],tmp[1001];
double num[1001];
int l=-1,sum,top;
double stack[1001],ans;
int main()
{
     gets(s); 
     for(int i=1;i<=1000;i++) num[i]=no;//num数组赋极值 
     for(int i=0;i<=strlen(s);i++)
     {
         if(s[i]==42||s[i]==43||s[i]==45||s[i]==47) tmp[++sum]=s[i];//运算符 
        else if((s[i]>='0'&&s[i]<='9')||s[i]==46) k[++l]=s[i];//数字或者小数点 
        else if(s[i-1]>='0'&&s[i-1]<='9') //只有数字之后的空格才需要把字符串转换成数字 
        {
            num[++sum]=atof(k);
            memset(k,'\0',sizeof(k));
            l=-1;//l从-1开始，因为上面k[++l]=s[i]，数组k从0开始赋值 
        } 
     }
     for(int i=sum;i>0;i--)//从右往左扫描 
     {
         if(num[i]!=no) stack[top++]=num[i];//不是极值，是数字，入栈 
         else //运算符，弹出栈顶两个数字运算 
         {
             double a=stack[--top],b=stack[--top];
            switch(tmp[i])
             {
                 case '+':ans=a+b;break;
                 case '-':ans=a-b;break;
                 case '*':ans=a*b;break;
                 case '/':ans=a/b;break;
            }
            stack[top++]=ans;//运算完结果入栈 
        }
     }
     printf("%f\n",stack[0]);
}
