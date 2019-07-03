#include <iostream>
using namespace std;
int n;
int dgxzb;
int c[30];
int a[30][30];
void dfs(int x);
int main() {
while(1) {
cin>>n;
if(n==0) break;
dgxzb=0;
dfs(1);
cout<<n<<" "<<c[n]<<endl;
}
}
void dfs(int x) {
if(x>n) return;
for(int i=0; i<=1; i++) {
a[1][x]=i;
dgxzb+=i;
for(int j=2; j<=x; j++) {
a[j][x-j+1]=a[j-1][x-j+2]^a[j-1][x-j+1];
dgxzb+=a[j][x-j+1];
}
if(dgxzb*2 == n*(n+1)/2) c[x]++;
dfs(x+1);
dgxzb-=i;
for(int j=2; j<=x; j++) {
a[j][x-j+1]=a[j-1][x-j+2]^a[j-1][x-j+1];
dgxzb-=a[j][x-j+1];
}
}
}
