#include<iostream>
using namespace std;
int n,m,b[101][101],cnt;
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
int x[10001],y[10001];
char a[101][101];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
      {
           cin>>a[i][j];
           if(a[i][j]=='*')
           {
               x[++cnt]=i;y[cnt]=j;
         }
      }
    for(int i=1;i<=cnt;i++)
    {
        int xx=x[i],yy=y[i];
        for(int j=0;j<8;j++)
        {
            int nx=xx+dx[j],ny=yy+dy[j];
            if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]!='*')
                b[nx][ny]++;
        }
    }
    for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=m;j++)
           if(a[i][j]=='*') cout<<'*';
           else cout<<b[i][j];
         cout<<endl;
     }
}

//统计出每个地雷的位置，以地雷为基准，周围8个非地雷的格子+1。预测应该比第二种方法快
