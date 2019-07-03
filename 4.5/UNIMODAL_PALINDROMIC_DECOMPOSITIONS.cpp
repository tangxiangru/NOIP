#include <iostream>
using namespace std;

#define N 300

long long *f[N]; //注意精度，用long long, 因为这个WA了好几次。

void compute(int n);

long long get(int n, int k) {
if (f[n][k]!=0)
return f[n][k];
else
compute(n);
return f[n][k];
}

void compute(int n) {
if (f[n][n] != 0) {
return;
}
for (int j = 1; j<=n/2;j++) {
if (n-2*j >= j) {
f[n][j] += get(n-2*j,j);
}
}
if ((n/2)*2 == n)
f[n][n/2] += 1;
f[n][n]=1;
for (int j=n-1; j>=1;j--) {
f[n][j] += f[n][j+1];
}
}



int main()
{
for (int i =0 ; i< N; i++) {
f[i] = new long long[i+1];
for (int j=0;j<=i;j++) {
f[i][j] = 0;
}
}

int n;
cin >> n;
f[1][1]=1;
while(n!=0)
{
compute(n);
cout << n << " " << f[n][1] << endl;
cin >> n;
}
}
