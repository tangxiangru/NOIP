#include<cstdio>
#include<cstring>
using namespace std;
int a[15],num;
char c;
bool two;
bool dfs(int x)
{
if(x==10)return true;
if(!a[x])return dfs(x+1);
if(a[x]&&a[x+1]&&a[x+2])
{
a[x]--,a[x+1]--,a[x+2]--;
if(dfs(x+!a[x]))return true;
a[x]++,a[x+1]++,a[x+2]++;
}
if(a[x]==1)return false;
if(!two)
{
two=true;
a[x]-=2;
if(dfs(x+!a[x]))return true;
a[x]+=2;
two=false;
}
if(a[x]==2)return false;
a[x]-=3;
if(dfs(x+!a[x]))return true;
a[x]+=3;
return false;
}
int main()
{
while((c=getchar())!='0')
{
memset(a,0,sizeof(a));
num=two=0;
do
if(c!=' ')a[c-'0']++,num++;
while((c=getchar())!='\n');
if(num%3<2)
{
printf("XIANGGONG\n");
continue;
}
if(dfs(1))printf("HU\n");
else printf("BUHU\n");
}
return 0;
}
