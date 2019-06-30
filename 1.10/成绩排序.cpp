#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct student
{
    string name;
    int score;
} stu[21];
bool operator<(student a, student b)
{
    if (a.score != b.score)
        return a.score > b.score;
    if (a.name.compare(b.name) <= 0)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> stu[i].name >> stu[i].score;
    stable_sort(stu, stu+n);
    for (int i=0; i<n; i++)
        cout << stu[i].name << " " << stu[i].score << endl;
    return 0;
}
