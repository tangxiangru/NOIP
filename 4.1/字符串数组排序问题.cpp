#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
int num;
string str;
}s1[10010];
int Com1(const Node &a,const Node &b){
return a.str<b.str;
}
int Com2(const Node &a,const Node &b){
return a.str>b.str;
}
int main(){
char s[10010][110],t[10];
string ss;
int n;
cin>>ss>>n;
gets(t);
for(int i=1;i<=n;i++){
gets(s[i]);
int len=strlen(s[i]),j,k;
for(j=0;j<len;j++)
if(s[i][j]==' ')
continue;
else break;
for(k=len-1;k>=0;k--)
if(s[i][k]==' ')
continue;
else break;
for(int p=j;p<=k;p++){
if(ss=="ncinc"||ss=="ncdec")
s1[i].str+=tolower(s[i][p]);
else
s1[i].str+=s[i][p];
s1[i].num=i;
}
}
if(ss=="inc"||ss=="ncinc")
sort(s1+1,s1+n+1,Com1);
if(ss=="dec"||ss=="ncdec")
sort(s1+1,s1+n+1,Com2);
for(int i=1;i<=n;i++)
cout<<s[s1[i].num]<<endl;
return 0;
}
