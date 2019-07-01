#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[2001];
int s;
int main()
{
    gets(a);
    int l=strlen(a);
    for(int i=0;i<l;i++)
    {
        if(a[i]!=‘ ‘) s++;
        else if(a[i]==‘ ‘&&a[i-1]!=‘ ‘) //排除掉多个空格相连的情况
        {
            cout<<s<<‘,‘;
            s=0;
        }
    }
    cout<<s;
}
