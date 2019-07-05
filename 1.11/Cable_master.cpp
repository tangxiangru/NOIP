/**
 * 在区间[0,maxa+1]之间进行二分查找。maxa是最长的网线的长度。注意这个题最小单位是厘米，所以干脆在输入数据时直接处理、保存长度是厘米的数据。
 * 对每一个二分的中间点进行检验（假设剪出来的网线长度是mid，那么可以得到多少条网线呢？假设为ans，那么ans是否大于m呢？若是ans小于m则说明剪得
 * 太长了，否则说明还可以剪得更长一些。）
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=10000+10;
int n, m, i;
int A[MAXN], maxa;
void solve()
{
    int L=0, R=maxa+1, mid;
    int ans = 0;
    while (L+1<R){
        ans = 0;
        mid = (L+R)/2;
        for (i=0; i<n; i++)
            ans += A[i]/mid;
        if (ans < m) R = mid;
        else L = mid;
    }
    cout << fixed << setprecision(2) << L/100.00 << endl;
}
int main()
{
    cin >>n >> m;
    maxa = 0;
    double t;
    for (i=0; i<n; i++){
        cin >> t;
        A[i] = t*100;
        maxa = max(maxa, A[i]);
    }
    solve();
    return 0;
}
