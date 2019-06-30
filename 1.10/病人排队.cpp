#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct patient
{
    string ID;
    int age;
    int order;
} pa[100];
bool operator<(patient a, patient b)
{
    if (a.age>=60 && b.age<60) return true;
    else if (a.age<60 && b.age>=60) return false;
    else{
        if (a.age>=60 && b.age>=60) return a.age>b.age;
        else return a.order<b.order;
    }
}
int main()
{
    int n, i;
    cin >> n;
    for (i=0; i<n; i++) {
        cin >> pa[i].ID >> pa[i].age;
        pa[i].order = i;
    }
    stable_sort(pa, pa+n);
    for (i=0; i<n; i++)
        cout << pa[i].ID << endl;
    return 0;
}
