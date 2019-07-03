#include <iostream>
#include <memory.h>
using namespace std;
void dfs(int x,int y,long k);
int n,m,l,a[105][105],dx[9]={0,2,2,1,1,-1,-1,-2,-2},dy[9]={0,-1,1,-2,2,-2,2,-1,1};
int main()
{

    int t,i,x,y,k,j;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        memset(a,0,sizeof(a));
        cin>>n>>m>>x>>y;
        l=0;
        x++;
        y++;
        a[x][y]=1;
        dfs(x,y,1);
        cout<<l<<endl;
    }
}
void dfs(int x,int y,long k)
{
    int tx,ty,i;
    if(k==n*m)l++;
    else
    for(i=1;i<=8;i++)
    {
        tx=x+dx[i];
        ty=y+dy[i];
        if(tx>0&&tx<=n&&ty>0&&ty<=m&&a[tx][ty]==0)
        {
            a[tx][ty]=1;
            dfs(tx,ty,k+1);
            a[tx][ty]=0;
        }
    }
}
