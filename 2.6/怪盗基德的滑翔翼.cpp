#include<iostream>
#include<cstring>
using namespace std;
int main(){
int k,n,a[110],f[110],m1,m2;
cin>>k;
for(int p=1;p<=k;p++){
cin>>n;m1=0;m2=0;
for(int i=1;i<=n;i++)
cin>>a[i];
memset(f,0,sizeof(f));
for(int i=1;i<=n;i++)
for(int j=1;j<i;j++)
if(a[j]<a[i]&&f[i]<f[j]+1)
f[i]=f[j]+1;
for(int i=1;i<=n;i++)
if(f[i]>m1)m1=f[i];
memset(f,0,sizeof(f));
for(int i=n;i>0;i--)
for(int j=n;j>i;j--)
if(a[j]<a[i]&&f[i]<f[j]+1)
f[i]=f[j]+1;
for(int i=1;i<=n;i++)
if(f[i]>m2)m2=f[i];
if(m2>m1)cout<<m2+1<<endl;
else cout<<m1+1<<endl;
}
return 0;
}
