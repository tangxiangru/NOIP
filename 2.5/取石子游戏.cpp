#include<cstdio>
#include<iostream>
using namespace std;
int i,j,n,m;
void dfs(int a,int b,int step){//step为次数
    if(!(a%b)||a/b>=2){//满足条件，打印跳出
        if(step%2!=0)
            printf("win\n");
        else
            printf("lose\n");
        return;
    }
    dfs(b,a%b,step+1);//继续搜索
}
int main()
{
    while(scanf("%d%d",&n,&m)==2){//读入
        if(n==0&&m==0)//如n和m都等于0，程序结束
            return 0;
        if(n<m)//始终n>=m
            swap(n,m);//把n和m互相交换
        if(n/m>=2){//满足提示，直接打印
            printf("win\n");
            continue;//下一次循环
        }
        dfs(n,m,1);//如果不符合，搜索
    }
}
