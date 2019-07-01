#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
int book[26][1000]={},m,i,j,n,MAX,_MAX=0;
char w[26];
cin>>m;
for(i=1;i<=m;i++)
{
cin>>n>>w;
for(j=0;j<strlen(w);j++)
{
book[w[j]-'A'][0]++;
book[w[j]-'A'][book[w[j]-'A'][0]]=n;
}
}
for(i=0;i<26;i++)
if(book[i][0]>_MAX)
{MAX=i;_MAX=book[i][0];}
cout<<(char)(MAX+'A')<<endl<<_MAX<<endl;
for(i=1;i<=book[MAX][0];i++)
cout<<book[MAX][i]<<endl;
return 0;
}
