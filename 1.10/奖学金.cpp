#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct student
{
    int no;
    int yuwen;
    int shuxue;
    int yingyu;
    int score;
} stu[300];
bool operator<(student a, student b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else {
        if (a.yuwen != b.yuwen)
            return a.yuwen > b.yuwen;
        else {
            return a.no < b.no;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> stu[i].yuwen >> stu[i].shuxue >> stu[i].yingyu;
        stu[i].no = i+1;
        stu[i].score = stu[i].yuwen+stu[i].shuxue+stu[i].yingyu;
    }
    stable_sort(stu, stu+n);
    for (int i=0; i<5; i++)
        cout << stu[i].no << " " << stu[i].score << endl;
    return 0;
}
