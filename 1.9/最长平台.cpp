#include <iostream>
using namespace std;
int main()
{
    int n, i, x, cur, len=1, maxl=1;
    cin >> n >> x;
    cur = x;
    for (i=1; i<n; i++){
        cin >> x;
        if (x == cur){
            len++;
        }
        else{
            len = 1;
            cur = x;
        }
        if (len > maxl) maxl = len;
    }
    cout << maxl << endl;
    return 0;
}
