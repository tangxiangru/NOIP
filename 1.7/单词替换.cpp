#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char s[501],a[501],b[501];
string f[101];
bool v[101];
int main(){
    gets(s);gets(a);gets(b);
    int k=1,l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]!=‘ ‘)
            f[k]+=s[i];
        else k++;
    }
    for(int i=1;i<=k;i++)
    {
        if(f[i]==a) cout<<b<<‘ ‘;
        else cout<<f[i]<<‘ ‘;
    }
}
