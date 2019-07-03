#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
vector<vector<ld> > a;
ld eps;
vector<ld> x[2],b,c;
int n;
bool check()
{
for(int i=1; i<n; i++)
{
if(fabs(x[0][i]-x[1][i]) > eps)
{
return true;
}
}
return false;
}
int main()
{
double tmp;
cin>>n>>tmp;
eps = tmp;
a.resize(n);
x[0].resize(n,0);
x[1].resize(n,0);
b.resize(n);
c.resize(n);
for(int i=0; i<n; i++) a[i].resize(n);
for(int i=0; i<n; i++)
{
for(int j=0; j<n; j++)
{
cin>>tmp;
a[i][j] = tmp;
}
cin>>tmp;
b[i] = tmp;
}
for(int i=0; i<n; i++) x[0][i] = b[i];
int e = 0;
do{
e ^= 1;
for(int i=0; i<n; i++)
{
x[e][i] = b[i];
for(int j=0; j<n; j++)
{
if(i == j) continue;
x[e][i] -= a[i][j]*x[e^1][j];
}
x[e][i] /= a[i][i];
}
}while(check());
int ans = 0;

for(int i=0; i<n; i++)
{
c[i] = 0;
for(int j=0; j<n; j++)
{
c[i] += a[i][j]*x[e][j];
}
if(fabs(b[i]-c[i]) > fabs(b[i])/10000.0)
{
ans++;
}
}
printf("%d\n",ans);
return 0;
}
