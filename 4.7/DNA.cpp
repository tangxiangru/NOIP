#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool visit[20]={};
int a[200]={};
string dna[20];
long int maxl=0;
int n;
long int pre(long int i,long int j){
long int k=0;
long int u;
string s1,s2;
u=min(dna[i].length(),dna[j].length());
s1=dna[i].substr(dna[i].length()-u,u);
s2=dna[j].substr(0,u);
while(s1!=s2&&k<u){
k+=1;
s1=dna[i].substr(dna[i].length()-u+k,u);
s2=dna[i].substr(0,u-k);
}
return u-k;
}
long int sum=0;
void dfs(int step,int co){
if(sum>=maxl)
return;
if(step>=n){
if(sum<maxl)
maxl=sum;
return;
}
for(int i=0;i<n;i++){
if(visit[i]==0){
if(dna[co].find(dna[i])!=dna[co].npos){
visit[i]=1;
dfs(step+1,i);
visit[i]=0;
}
else{
int l=a[co*10+i];

sum+=(dna[i].length()-l);
visit[i]=true;
dfs(step+1,i);
visit[i]=false;
sum-=(dna[i].length()-l);
}
}
}
}
int main(){
int t;
cin>>t;
while(t>0){
sum=0;
memset(a,0,sizeof(a));
memset(visit,0,sizeof(visit));
maxl=INT_MAX;
cin>>n;
for(int i=0;i<n;i++){
cin>>dna[i];
}
for(int i=0;i<n;i++)
for(int j=0;j<n;j++){
if(i!=j){
long int l=0;
for(int k=0;k<dna[i].length();k++){
int start=dna[j].find(dna[i].substr(k));
if(start==0){
l=dna[i].length()-k;
break;
}
}
a[10*i+j]=l;
}
}
for(int i=0;i<n;i++){
visit[i]=1;
sum=dna[i].length();
dfs(1,i);
visit[i]=0;
}
cout<<maxl<<endl;
--t;
}
}
