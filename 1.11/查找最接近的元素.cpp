#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, m, i, x, y, mid, target;
    int a[100000]; // 非降序列
    cin >> n;
    for (i=0; i<n; i++) cin >> a[i];
    cin >> m;
    for (i=0; i<m; i++){
        cin >> target;
        x = 0;
        y = n-1;
        while ((y-x) > 1){
            mid = (y-x) / 2 + x;
            if (a[mid] == target){
                x = y = mid;
            }
            else{
                if (a[mid] > target)
                    y = mid;
                else
                    x = mid;
            }
        }
        if (x == y) cout << a[x] << endl;
        else {
            if ((target-a[x]) <= (a[y]-target))
                cout << a[x] << endl;
            else
                cout << a[y] << endl;
        }
    }
}
