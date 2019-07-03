#include<bits/stdc++.h>
using namespace std;
int main()
{
int p[4];
string ans,b;
cin>>p[1]>>p[2]>>p[3]>>b;
for(int i=0;i<b.size();i++)
if(b[i]=='-'&&((b[i-1]>='a'&&b[i-1]<='z'&&b[i+1]>='a'&&b[i+1]<='z')||(b[i-1]>='0'&&b[i-1]<='9'&&b[i+1]>='0'&&b[i+1]<='9'))&&b[i-1]<b[i+1])
{
string h;
for(int j=b[i-1]+1;j<b[i+1];j++)
for(int k=1;k<=p[2];k++)
{
if(p[1]==1)h+=j;
if(p[1]==2)
{if(j>='a'&&j<='z')
h+=(j-('a'-'A'));
else
h+=(j);
}
if(p[1]==3)h+='*';
}
if(p[3]==2){
for(int k=0;k<h.size();k++)
cout<<h[h.size()-k-1];}
else cout<<h;
}
else
if(b[i-1]>b[i+1]&&b[i]=='-')cout<<'-';
else cout<<b[i];
cout<<endl;
}
