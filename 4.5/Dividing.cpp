#include<bits/stdc++.h>
using namespace std;
int f[420010],que[420010];
int main(){
int a[7],c=0;
while (cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]){
int tot=0;
tot=a[1]+a[2]*2+a[4]*4+a[3]*3+a[5]*5+a[6]*6;
if (tot){
if (tot%2!=0){
printf("Collection #%d:\n",++c);
cout<<"Can't be divided."<<endl;
cout<<endl;
}
else{
memset(f,0,sizeof(f));
f[0]=1;
for (int i=1;i<=6;i++){
if (a[i]==1){
for (int j=tot/2;j>=i;j--)
if (f[j-i]) f[j]=1;
}
else if (a[i]*i>=tot/2){
for (int j=i;j<=tot/2;j++)
if (f[j-i]) f[j]=1;
}
else if (a[i]){
memset(que,0,sizeof(que));
for (int d=0;d<i;d++){
int h=1,t=0,sum=0;
for (int v=d;v<=tot/2;v+=i){
if (t-h==a[i]){
sum-=que[h];
h++;
}
sum+=f[v];
que[++t]=f[v];
if (sum) f[v]=1;
}
}
}
}
if (f[tot/2]){
printf("Collection #%d:\n",++c);
cout<<"Can be divided."<<endl;
cout<<endl;
}
else{
printf("Collection #%d:\n",++c);
cout<<"Can't be divided."<<endl;
cout<<el;
}
}
}
else return 0;
}
return 0;
}
