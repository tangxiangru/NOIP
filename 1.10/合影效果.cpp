#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct student
{
    string sex;
    double high;
} stu[40];
bool operator<(student a, student b)
{
    if (a.sex.compare("male")==0 && b.sex.compare("female")==0) return true;
    else if (a.sex.compare("female")==0 && b.sex.compare("male")==0) return false;
    else{
        if (a.sex.compare("male")==0 && b.sex.compare("male")==0) return a.high<b.high;
        else return a.high>b.high;
    }
}
int main()
{
    int n, i;
    cin >> n;
    for (i=0; i<n; i++) cin >> stu[i].sex >> stu[i].high;
    stable_sort(stu, stu+n);
    for (i=0; i<n; i++)
        cout << fixed << setprecision(2) << stu[i].high << " ";
    return 0;
}
