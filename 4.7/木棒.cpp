#include<cstdio>
#include<cstdlib>
#include<algorithm>
int n,cnt,sum,maxx,flag,t,m;
int a[100];
bool b[100];
using namespace std;
int cmp(const int&a,const int&b)
{
return a>b;
}
void dfs(int l,int s){
if(flag) return;
if(s==m){
s=0;
l++;
}
if(l==t-1){
flag=1;
return;
}
for(int i=1;i<=cnt;i++){
if(s+a[i]>m||b[i]) continue;
if(a[i]==a[i-1]&&!b[i-1]) continue;
b[i]=1;
dfs(l,s+a[i]);
b[i]=0;
if(flag)return;
if(s==0)return;
}
}
int init()
{
int x;
for(int i=1;i<=n;i++){
scanf("%d",&x);
if(x<=50){
a[++cnt]=x;
sum+=x;
maxx=max(maxx,x); }
}
}
int main(){
int i,j,k;
while(1){
cnt=0;sum=0;maxx=0;
scanf("%d",&n);
if(n==0)return n;
init();
sort(a+1,a+n+1,cmp);
for(i=maxx;i<=sum;i++){
if(sum%i==0){
t=sum/i;
m=i;
flag=0;
dfs(0,0);
if(flag){
printf("%d\n",i);
break;
}
}
}
}
return 0;
}
