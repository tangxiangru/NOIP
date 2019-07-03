#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1010;
const int val[10]={0,10,20,50,100};
int n,f[maxn];
void Init();

int main(){
Init();
system("pause");
return 0;
}
void Init(){
scanf("%d",&n);
f[0]=1;
for(int i=1;i<=4;i++){
for(int j=val[i];j<=n;j++){
f[j]=f[j-val[i]]+f[j];
}
}
printf("%d\n",f[n]);
}
