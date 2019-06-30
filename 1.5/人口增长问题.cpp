#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int x, n;
    double people;
    cin >> x >> n;
    people = x;
    for (int i=0; i<n; i++){
        people *= (100.1/100);
    }
    cout << fixed << setprecision(4) << people << endl;
    return 0;
}
