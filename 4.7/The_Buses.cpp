#include<iostream>
#include<fstream>
#include<algorithm>
#include<climits>
using namespace std;
 
struct route {
    int start, inter, cnt;                  // 首班时间，时间间隔，班次
 
    route(int st, int in, int cn): start(st), inter(in), cnt(cn){}
    route(void){}
    bool operator< (const route &b) const   // 按班次降序排序
    {
        return cnt > b.cnt;
    }
};
 
int a[65] = {};                             // 该时刻在时间表中出现次数
route rt[905] = {};                         // 所有可能的路线
int n = 0;                                  // 记录条数
int ans = 17;								// 最小的路线数, 题目中说了答案<=17, 利用这点信息可以大大减少时间
int rtcnt = 0;                              // 所有可能的路线数
 
int check(int start, int inter)             // 给定首班时间和时间间隔，计算班次；如果该班次不可能出现，则返回0
{
    if (start-inter>=0)                     // 如果首班之前还有，则不是该班次不可能出现
    {
        return 0;
    }
    int cur = start, cnt = 0;
    while (cur <= 59)
    {
        if (!a[cur])                        // 如果有一个班次时间没有记录，则该班次不可能出现
        {
            return 0;
        }
        cnt++;
        cur += inter;
    }
    return cnt;
}
 
void dfs(int k, int routes, int records)    // 当前正在计算的班次在rt数组中的下标，已经使用的班次，已经命中的记录
{
    if (records==n)
    {
        ans = min(ans, routes);
        return;
    }
    int i,j;
    for (i=k; i<rtcnt; i++)                 // 两条公交线路的时刻表可以完全相同，故i可以等于k
    {
        if (routes + (n-records)/rt[i].cnt >= ans)  // 最优性剪枝：如果当前剩余的记录按当前过站最多的路线算总路线也比ans多
        {
            return;                                 // 剪枝
        }
        if (check(rt[i].start, rt[i].inter))        // 这里要重新判断可行性是因为已经有一些路线占用了记录
        {
            for (j=rt[i].start; j<=59; j+= rt[i].inter)
            {
                a[j]--;
            }
            dfs(i, routes+1, records+rt[i].cnt);    // 递归深搜
            for (j=rt[i].start; j<=59; j+= rt[i].inter) // 恢复
            {
                a[j]++;
            }
        }
    }
}
 
int main()
{
#ifndef ONLINE_JUDGE
    ifstream fin ("0407_169.txt");
    int i,j,tmp;
    fin >> n;
    for (i=0; i<n; i++)
    {
        fin >> tmp;
        a[tmp]++;
    }
    fin.close();
    int mycnt = 0;
    for (i=0; i<30; i++)
    {
        for (j=i+1; j<=59-i; j++)
        {
            mycnt = check(i,j);
            if (mycnt)
            {
                rt[rtcnt++] = route(i,j,mycnt);
            }
        }
    }
    sort(rt, rt+rtcnt);
    ans = 17;
    dfs(0,0,0);
    cout << ans;
    return 0;
#endif
#ifdef ONLINE_JUDGE
	int i,j,tmp;
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }
    int mycnt = 0;
    for (i=0; i<30; i++)
    {
        for (j=i+1; j<=59-i; j++)
        {
            mycnt = check(i,j);
            if (mycnt)
            {
                rt[rtcnt++] = route(i,j,mycnt);
            }
        }
    }
    sort(rt, rt+rtcnt);
    ans = 17;
    dfs(0,0,0);
    cout << ans;
    return 0;
#endif
}
