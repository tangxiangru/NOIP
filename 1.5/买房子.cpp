#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int N, K, i;
    double house = 200;
    double money;
    cin >> N >> K;
    money = N;
    for (i=1; i<=20; i++){
        if (money >= house) break;
        house *= (100+K)/100.0;
        money += N;
    }
    if (i == 21) cout << "Impossible" << endl;
    else cout << i << endl;
    return 0;
}
