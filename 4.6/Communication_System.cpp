#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

struct node{
double B,P;
bool operator <(const node nxt)const{
return P<nxt.P;
}
}a[105][105];
int cnt[105];


int main(){
int t,n;
scanf("%d",&t);
while(t--){
double ans=0;
set<double>s;
memset(cnt,0,sizeof cnt);
scanf("%d",&n);
for(int i=1;i<=n;i++){
scanf("%d",&cnt[i]);
for(int j=1;j<=cnt[i];j++){
scanf("%lf%lf",&a[i][j].B,&a[i][j].P);
s.insert(a[i][j].B);
}
sort(a[i]+1,a[i]+1+cnt[i]);
}

set<double>::iterator it;
for(it=s.begin();it!=s.end();it++)
{
double sum=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=cnt[i];j++)
if(a[i][j].B>=*it){
sum+=a[i][j].P;
break;
}
else if(j==cnt[i]) sum=1<<29;

ans=max(ans,*it/sum);
}
printf("%.3lf\n",ans);
}
}
