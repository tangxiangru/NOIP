#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n, i;
    double data, avg, sum=0;
    cin >> n;
    for (i=0; i<n; i++){
        cin >> data;
        sum += data;
    }
    avg = sum/n;
    cout << fixed << setprecision(4) << avg << endl;
    return 0;
}
