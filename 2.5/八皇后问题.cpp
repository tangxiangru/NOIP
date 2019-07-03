#include<bits/stdc++.h>
using namespace std;
int a[20],b[20]={},c[20]={},d[20]={},k=0;
int fa(int i)
{
int e[9][9]={},j;
for(j=1;j<=8;j++)
if((!b[j])&&(!c[i+j])&&(!d[i-j+7]))
{
a[i]=j;b[j]=1;c[i+j]=1;d[i-j+7]=1;
if(i==8)
{
k++;
cout<<"No. "<<k<<endl;
int h,x,y;
for(h=1;h<=8;h++)
e[a[h]][h]=1;
for(x=1;x<=8;x++)
{
for(y=1;y<=8;y++)
cout<<e[x][y]<<" ";
cout<<endl;
}
}
else fa(i+1);
b[j]=0;c[i+j]=0;d[i-j+7]=0;
}
}
int main()
{
fa(1);
}

