#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum, known=0, x;
    cin >> n;
    sum = (n-2)*180;
    for (int i=0; i<n-1; i++){
        cin >> x;
        known += x;
    }
    cout << sum-known << endl;
    return 0;
}
