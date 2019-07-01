#include<iostream>
using namespace std;
int n;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int a[101][101]; 
bool v[101][101];
int s,bian;
void dfs(int x,int y)
{
    s++;
    int ok=0;
    for(int i=0;i<4;i++)
     {
         int nx=x+dx[i],ny=y+dy[i];
         if(nx>0&&nx<=n&&ny>0&&ny<=n&&a[nx][ny]<=50)
          {
              if(!v[nx][ny])
            {
              v[nx][ny]=true;
                dfs(nx,ny);
            }
         }
        else ok=1;
     }
     if(ok) bian++;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      cin>>a[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(a[i][j]<=50&&!v[i][j]) 
       {
             v[i][j]=true;
             dfs(i,j);
       }
   cout<<s<<' '<<bian;
    return 0;
} 

