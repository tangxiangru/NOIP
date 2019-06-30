#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(int a, int b)
{
    if (a%2==1 && b%2==0) return true;
    else if (a%2==0 && b%2==1) return false;
    else {
        if (a%2==0 && b%2==0) return a<b;
        else return a>b;
    }
}
int main()
{
    int a[10], i;
    for (i=0; i<10; i++) cin >> a[i];
    sort(a, a+10, cmp);
    for (i=0; i<10; i++) cout << a[i] << " ";
    return 0;
}
