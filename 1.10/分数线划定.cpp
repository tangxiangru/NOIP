#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct student
{
    int no;
    int score;
} stu[5000];
bool operator<(student a, student b)
{
    if (a.score != b.score)
        return a.score > b.score;
    return a.no < b.no;
}
int main()
{
    int n, m, want, i;
    int score, num=0;
    cin >> n >> m;
    want = floor(m*1.5);
    for (int i=0; i<n; i++){
        cin >> stu[i].no >> stu[i].score;
    }
    stable_sort(stu, stu+n);
    score = stu[want-1].score;
    num = want;
    for (i=want; i<n; i++){ // 处理重分
        if (stu[i].score == stu[want-1].score){
            num++;
        }
    }
    cout << score << " " << num << endl;
    for (i=0; i<num; i++)
        cout << stu[i].no << " " << stu[i].score << endl;
    return 0;
}
