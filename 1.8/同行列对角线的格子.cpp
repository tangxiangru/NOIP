#include<iostream>
#include<cstdio>
using namespace std;
int a[11][11],n,x,y;
void dg(int i,int j)//在给定格子左下方的部分回溯输出
{
    if(i==n+1||j==0) return;
    dg(i+1,j-1);
    printf("(%d,%d) ",i,j);
}
void dg2(int i,int j)//给定格子右上方的递归直接输出
{
    if(i==0||j==n+1) return;
    printf("(%d,%d) ",i,j);
    dg2(i-1,j+1);
}
int main()
{
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++) 
     printf("(%d,%d) ",x,i);
    cout<<endl;
    for(int i=1;i<=n;i++)
     printf("(%d,%d) ",i,y);
    cout<<endl;
    int c=x-y;
    if(c<=0)//x<y
    {
        for(int i=1;i-c<=n;i++)
         printf("(%d,%d) ",i,i-c);
    }
    else if(c>0)//x>y
    {
        for(int i=1;i+c<=n;i++)
         printf("(%d,%d) ",i+c,i);
    }
    cout<<endl;
    dg(x,y);
    dg2(x-1,y+1);
}
