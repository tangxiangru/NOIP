#include <bits/stdc++.h>
using namespace std;
int main(){
    int k, num, one=0, five=0, ten=0;
    cin >> k;
    for (int i=0; i<k; i++){
        cin >> num;
        if (num == 1) one++;
        else if (num == 5) five++;
        else if (num == 10) ten++;
    }
    cout << one << endl;
    cout << five << endl;
    cout << ten << endl;
    return 0;
}
