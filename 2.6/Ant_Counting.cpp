#include <cstdio>

#include <cstring>

#include <cmath>

#include <string>

#include <iostream>

#include <algorithm>

#include <queue>

using namespace std;

#define rep(i, n) for(int i=0; i<(n); ++i)

#define for1(i,a,n) for(int i=(a);i<=(n);++i)

#define for2(i,a,n) for(int i=(a);i<(n);++i)

#define for3(i,a,n) for(int i=(a);i>=(n);--i)

#define for4(i,a,n) for(int i=(a);i>(n);--i)

#define CC(i,a) memset(i,a,sizeof(i))

#define read(a) a=getint()

#define print(a) printf("%d", a)

#define dbg(x) cout << #x << " = " << x << endl

#define printarr(a, n, m) rep(aaa, n) { rep(bbb, m) cout << a[aaa][bbb]; cout << endl; }

inline const int getint() { int r=0, k=1; char c=getchar(); for(; c<'0'||c>'9'; c=getchar()) if(c=='-') k=-1; for(; c>='0'&&c<='9'; c=getchar()) r=r*10+c-'0'; return k*r; }

inline const int max(const int &a, const int &b) { return a>b?a:b; }

inline const int min(const int &a, const int &b) { return a<b?a:b; }



const int N=1005, md=1e6;

int a[N], n, m, f[N*100], l, r, ans;



int main() {

read(n); read(m); read(l); read(r);

for1(i, 1, m) ++a[getint()];

for1(i, 0, a[1]) f[i]=1;

for1(i, 2, n) {

for3(j, r, 0)

for1(k, 1, a[i]) if(j<k) break; else f[j]=(f[j]+f[j-k])%md;

}

for1(i, l, r) ans=(ans+f[i])%md;


printf("%d\n", ans);

return 0;

}
