#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[1001],b[1001];
int main(){
    gets(a);
    int la=strlen(a);
    for(int i=0;i<la;i++)
    {
        if(a[i]==‘ ‘) 
        {
            for(int j=b[0];j>0;j--) cout<<b[j];//若多个空格相连，b[0]=0，不会有输出
            b[0]=0;
            cout<<‘ ‘;
        }
        else b[++b[0]]=a[i];
    }
    for(int j=b[0];j>0;j--) cout<<b[j];//若最后一个但此后面没有空格，执行此句输出
}
