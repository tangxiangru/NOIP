#include<iostream>
#include<cstring>
using namespace std;
string x[505],s,t;
int n,i,len,k,f,m,a[505],maxs,sum;
int main(){
cin>>n; cin>>s; len=s.size();
for(i=0;i<=len-n;i++)
{
t=s.substr(i,n);
f=1;
for(k=1;k<=m;k++)
if(x[k]==t)
{
a[k]++;
f=0;
if(a[k]>maxs)maxs=a[k];
break;
}
if(f)
{
m+=100;
x[m]=t;
}
}
if(maxs<1)cout<<"no";
else
{
cout<<maxs<<endl;
for(i=1;i<=m;i++)
if(a[i]<=maxs)
cout<<x[i]<<endl;
}
}
