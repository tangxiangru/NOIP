#include<bits/stdc++.h>
using namespace std;
int n1,n2,d1,d2,m1,m2;
int ans1=0,ans=0;
int ans2=0;
int q[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int cont(int n,int m,int d){
int tot=0;
tot+=d;
for(int i=1;i<m;i++)
tot+=q[i];
if(m>3){
if(n%100==0&&n%400!=0)
tot--;
if(n%4==0)
tot++;
}
return tot;
}

int pan(int n){
if(n%100==0&&n%400!=0)
return 365;

if(n%4==0)
return 366;

return 365;
}

int main(){
cin>>n1>>m1>>d1;
cin>>n2>>m2>>d2;
ans1=cont(n1,m1,d1);
ans2=cont(n2,m2,d2);
ans=ans2-ans1;
for(int i=n1;i<n2;i++)
ans+=pan(i);

cout<<ans<<endl;
return 0;
}
