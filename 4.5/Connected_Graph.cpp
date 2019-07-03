#include<cstring>
#include<iostream>
using namespace std;
long long f[51][1001],c[51][51],t[10001],b[51][10001];
int main(){
//freopen("tab.in","w",stdout);
for (int i=1;i<=50;i++)
c[i][0]=c[i][i]=1;
for (int i=1;i<=50;i++)
for (int j=1;j<i;j++)
c[i][j]=c[i-1][j-1]+c[i-1][j];
for (int i=1;i<=50;i++)
f[i][0]=f[i][1]=b[i][0]=b[i][1]=1;
for (int i=3;i<=50;i++)
for (int j=1;j<=(i-1)*i/2;j++){
for (int k=1;k<=f[i][0];k++)
f[i][k]*=2;
for (int k=1;k<=f[i][0];k++)
if (f[i][k]>=10) f[i][k+1]+=f[i][k]/10,f[i][k]%=10;
while(f[i][f[i][0]+1]>0){
f[i][0]++;
f[i][f[i][0]+1]+=f[i][f[i][0]]/10,f[i][f[i][0]]%=10;
}
}
for (int i=1;i<=50;i++)
for (int j=1;j<=(i-1)*i/2;j++){
for (int k=1;k<=b[i][0];k++)
b[i][k]*=2;
for (int k=1;k<=b[i][0];k++)
if (b[i][k]>=10) b[i][k+1]+=b[i][k]/10,b[i][k]%=10;
while(b[i][b[i][0]+1]>0){
b[i][0]++;
b[i][b[i][0]+1]+=b[i][b[i][0]]/10,b[i][b[i][0]]%=10;
}
}
for (int i=3;i<=50;i++)
for (int j=1;j<i;j++){
memset(t,0,sizeof(t)); t[0]=f[j][0]+b[i-j][0]-1;
for (int k=1;k<=f[j][0];k++)
for (int l=1;l<=b[i-j][0];l++)
t[k+l-1]+=f[j][k]*b[i-j][l];
for (int k=1;k<=t[0];k++)
if (t[k]>=10) t[k+1]+=t[k]/10,t[k]%=10;
while (t[t[0]+1]>0){
t[0]++;
t[t[0]+1]+=t[t[0]]/10,t[t[0]]%=10;
}
for (int k=1;k<=t[0];k++)
t[k]*=c[i-1][j-1];
for (int k=1;k<=t[0];k++)
if (t[k]>=10) t[k+1]+=t[k]/10,t[k]%=10;
while (t[t[0]+1]>0){
t[0]++;
t[t[0]+1]+=t[t[0]]/10,t[t[0]]%=10;
}
for (int k=1;k<=f[i][0];k++)
f[i][k]-=t[k];
for (int k=1;k<=f[i][0];k++)
if (f[i][k]<0) f[i][k]+=10,f[i][k+1]--;
while (!f[i][f[i][0]]) f[i][0]--;
}
int i;
while(cin>>i&&i!=0){
for (int j=f[i][0];j>0;j--)
cout<<f[i][j];
cout<<endl;
}
return 0;
}
