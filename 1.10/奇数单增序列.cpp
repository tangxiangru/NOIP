#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a[500], b[500], N, len=0, i;
    cin >> N;
    for (i=0; i<N; i++){
        cin >> a[i];
        if (a[i]%2 != 0){ // 是奇数
            b[len++] = a[i];
        }
    }
    sort(b, b+len);
    for (i=0; i<len; i++){
        cout << b[i];
        if (i != len-1)
            cout << ",";
    }
    return 0;
}
