#include<iostream>
using namespace std;
int n, a, b, i,j,k;
long long z[25][20][20];
int main(){
cin >> n >> a >> b;
for(i=0;i<=a;i++)for(j=0;j<=b;j++)z[1][i][j]=(i+1)*(j+1);
for(i=2;i<=n;i++)for(j=0;j<=a;j++){
for(k=0;k<=b;k++) z[i][j][k]=z[i-1][j][k]+z[i][j][k-1];
for(k=0;k<=b;k++) z[i][j][k]+=z[i][j-1][k];
}
cout << z[n][a][b] << endl;
return 0;
}
