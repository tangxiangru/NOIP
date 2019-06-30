#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n, data, i;
    double avg, sum=0;
    cin >> n;
    for (i=0; i<n; i++){
        cin >> data;
        sum += data;
    }
    avg = sum/n;
    cout << (int)sum << " " << fixed << setprecision(5) << avg << endl;
    return 0;
}
