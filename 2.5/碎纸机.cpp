#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int maxx;
int n,b[1000001],a[1000001],cf;
char s[100001];
int lenn;
void up(int l,int t,int ac)
{
if(l==lenn)
{
ac+=t;
if(ac>maxx&&ac<=n)
{
maxx=ac;cf=0;
for(int i=1;i<l;i++)a[i]=b[i];
}
else if(ac==maxx)cf=1;
return;
}
b[l]=0;up(l+1,t*10+s[l]-'0',ac);
b[l]=1;up(l+1,s[l]-'0',ac+t);
}
int main()
{
while(cin>>n>>s&&n)
{
lenn=strlen(s);
cf=0;
maxx=-1000001;
up(1,s[0]-'0',0);
if(maxx==-1000001)cout<<"error"<<endl;
else if(cf==1)cout<<"rejected"<<endl;
else
{
cout<<maxx<<' ';
for(int i=0;i<lenn;i++)
{
cout<<s[i];
if(a[i+1]==1)cout<<' ';
}
cout<<endl;
}
}
return 0;
}
