#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
bool check(double mid)
{
    double f = pow(mid,5)-15.0*pow(mid,4)+85.0*pow(mid,3)-225.0*pow(mid,2)+274.0*mid-121.0;
    if(f > 0.0) return 1;
    return 0;
}
int main()
{
    double l=1.5, r=2.4, mid;
    while(r-l > 0.00000001){
        mid = (l+r)/2.0;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << mid << endl;
    return 0;
}
