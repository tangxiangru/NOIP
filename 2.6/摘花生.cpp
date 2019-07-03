#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int __t;
    cin>>__t;//读入数据的数量
    for(int _t=1;_t<=__t;_t++){//循环_t次
        int x,y,a[102][102];
        cin>>x>>y;//读入数矩的大小
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                cin>>a[i][j];//读入
        for(int i=1;i<=x;i++)
            for(int j=1;j<=y;j++)
                a[i][j]+=max(a[i-1][j],a[i][j-1]);//递归查找最大
        cout<<a[x][y]<<endl;//输出最大的结果
    }
}
