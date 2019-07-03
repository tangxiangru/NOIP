#include <iostream>
#include <memory.h>
using namespace std;
int a[1005][1005],n,m,room,block,maxblock,dx[8]={2,0,-2,0},dy[8]={0,2,0,-2};
void dfs(int x,int y)
{
    int i,tx,ty;
    for(i=0;i<=7;i++)
      {
        tx=x+dx[i];
        ty=y+dy[i];
        if (tx>0&&tx<=2*n&&ty>0&&ty<=2*m&&a[tx][ty]==0&&a[x+dx[i]/2][y+dy[i]/2]==0)
          {
            block++;
            a[tx][ty]=1;
            a[x+dx[i]/2][y+dy[i]/2]=1;
            dfs(tx,ty);
          }
      }
}
int main()
{
    int i,k,j;
    cin>>n>>m;
    memset(a,0,sizeof(a));
    for(i=0;i<=2*n;i++)
    {
        a[i][0]=1;
        a[i][2*m]=1;
    }
    for(i=0;i<=2*m;i++)
    {
        a[0][i]=1;
        a[2*n][i]=1;
    }
    for(i=1;i<=2*n;i=i+2)
      for(j=1;j<=2*m;j=j+2)
        {
            cin>>k;
            if(k>=8)
            {
                a[i+1][j]=1;
                k-=8;
            }
            if(k>=4)
            {
                a[i][j+1]=1;
                k-=4;
            }
            if(k>=2)
            {
                a[i-1][j]=1;
                k-=2;
            }
            if(k>=1)
              a[i][j-1]=1;
        }
    for(i=1;i<=2*n;i=i+2)
      for(j=1;j<=2*m;j=j+2)
        if(a[i][j]==0)
          {
            block=1;
            room++;
            a[i][j]=1;
            dfs(i,j);
            if(block>maxblock)maxblock=block;
          }
    cout<<room<<endl<<maxblock<<endl;
}
