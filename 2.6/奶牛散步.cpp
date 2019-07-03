#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

long long ways[1005][4]; //long long (0ms) 比 int (4,8ms) 快....

int main(){
int n;
cin>>n;
for(int i=0;i<3;i++)
ways[1][i]=1;
ways[1][3]=3;
for(int i=2;i<=n;i++){
ways[i][0]=(ways[i-1][2]+ways[i-1][0])%12345;
ways[i][1]=(ways[i-1][2]+ways[i-1][1])%12345;
ways[i][2]=ways[i-1][3];
ways[i][3]=(ways[i][0]+ways[i][2]+ways[i][1])%12345;
}
if(n==0) cout<<0<<endl;
else cout<<ways[n][3]<<endl;
return 0;
}
