#include<stdio.h>
#include<string.h>
#include<algorithm>
#define M 100
using namespace std;

int n,Mlen,a[M],mark[M];

int cmp(int a,int b){
return a>b;
}

int dfs(int N,int now){
int i,j;
if(N==0 && now==0){
return 1;
}
if(now==0){
now=Mlen;
}
for(i=0;i<n;i++){
if(!mark[i] && a[i]<=now){
if(i>0){
if(!mark[i-1] && a[i-1]==a[i]) continue;//对于相等的就可以省去搜索
}
mark[i]=1;
if(dfs(N-1,now-a[i]))return 1;//dfs的还原。。。
else {
mark[i]=0;
if(a[i]==now || now==Mlen) return 0;
}
}
}
return 0;
}

int main(){
int i,j,sum;
while(scanf("%d",&n),n){
sum=0;
for(i=0;i<n;i++){
scanf("%d",&a[i]);
sum+=a[i];
}
sort(a,a+n,cmp);
for(i=a[0];i<=sum/2;i++){
if(sum%i==0){
for(j=0;j<n;j++){
mark[j]=0;
}
Mlen=i;
if(dfs(n,Mlen)){
printf("%d\n",Mlen);
break;
}
}
}
if(i>sum/2)printf("%d\n",sum);
}
return 0;
}
