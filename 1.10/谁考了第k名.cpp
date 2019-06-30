#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct student
{
    int no;
    double score;
} stu[101];
bool operator<(student a, student b)
{
    return a.score > b.score;
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> stu[i].no >> stu[i].score;
    stable_sort(stu, stu+n);
    cout << stu[k-1].no << " " << stu[k-1].score << endl;
    return 0;
}
