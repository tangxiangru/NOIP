#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;
const int MAX = 21;
long long w[MAX][MAX], m[MAX][MAX];
bool flag[MAX];
bool print;

void fand(int k, int n){
for (int i = 1; i <= n; i++) if (flag[i] && i <= k) k++, n++;
flag[k] = true;
if (print) cout<<" "<<k;
else{
cout<<k;
print = true;
}
}

int main(){
memset(w, 0, sizeof(w));
memset(m, 0, sizeof(m));
w[1][1] = 1; m[1][1] = 1;
w[1][2] = 0; m[1][2] = 1;
w[2][2] = 1; m[2][2] = 0;
for (int i = 3; i < MAX; i++) for (int j = 1; j < MAX; j++){
for (int k = 1; k < j; k++) w[j][i] += m[k][i - 1];
for (int k = j; k < i; k++) m[j][i] += w[k][i - 1];
}
int t, n;
long long c;
cin>>t;
while(t--){
cin>>n>>c;
int k = 1;
print = false;
bool direct = true, first = true;
memset(flag, false, sizeof(flag));
while(n)
if (direct)
if (c > w[k][n]){
c -= w[k++][n];
if (first) direct = false, k--;
}else{
fand(k, n--);
first = false;
direct = false;
k = 1;
}
else
if (c > m[k][n]){
c -= m[k++][n];
if (first) direct = true;
}else{
fand(k, n--);
first = false;
direct = true;
}
cout<<endl;
}
return 0;
}
