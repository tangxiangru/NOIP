#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int n, age, i;
    double avg, sum=0;
    cin >> n;
    for (i=0; i<n; i++){
        cin >> age;
        sum += age;
    }
    avg = sum/n;
    cout << fixed << setprecision(2) << avg << endl;
    return 0;
}
