#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m, n, i, j, time=0, w[10000]={0}, tap[100]={0};
    cin >> n >> m;
    for (i=0; i<n; i++) cin >> w[i];
    for (i=0; i<m; i++) tap[i] = w[i]; // 首先m个同学去接水
    while (i < n){ // 逐个模拟剩下的n-m个同学
        // 计算当前换人所需（最小）时间
        int substitution = tap[0];
        for (j=1; j<m; j++) substitution = min(substitution, tap[j]);
        time += substitution; // 换人时间累加进总时间
        // 计算换人时，水龙头前m个同学还需要的水量
        for (j=0; j<m; j++){
            tap[j] -= substitution;
            if (tap[j] == 0) tap[j] = w[i++]; // 换人
        }
    }
    // 处理最后剩下的m个同学
    int left = 0;
    for (i=0; i<m; i++){
        left = max(left, tap[i]);
    }
    cout << time+left << endl;
    return 0;
}
