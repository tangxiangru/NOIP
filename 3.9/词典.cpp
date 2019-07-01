#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map<string,string>mp;
char a[11],b[11],c[22];
int main()
{
    while(gets(c)&&c[0])
    {
        sscanf(c,"%s%s",a,b);
        mp[b]=a;
    }
    while(gets(c)&&c[0])
    {
        if(mp.find(c)!=mp.end()) cout<<mp[c]<<endl;
        else cout<<"eh"<<endl;
    }
}
