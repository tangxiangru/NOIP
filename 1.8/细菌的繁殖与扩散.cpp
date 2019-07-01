#include<bits/stdc++.h>
using namespace std;
int G[15][15],m,n,a[15][15],dx[]={0,0,1,-1,1,-1,1,-1},dy[]={-1,1,0,0,1,-1,-1,1};
int main()
{
      cin>>m>>n;G[5][5]=m;
      while(n--)
      {
         memset(a,0,sizeof(a));
         for(int i=1;i<=9;i++)
           for(int j=1;j<=9;j++)
            {
              a[i][j]+=G[i][j]*2;
              for(int k=0;k<8;k++)
              a[i+dx[k]][j+dy[k]]+=G[i][j];
            }
         memcpy(G,a,sizeof(a));
     }
     for(int i=1;i<=9;i++)
      {
          for(int j=1;j<=9;j++)
           cout<<G[i][j]<<' ';
          cout<<endl;
      }
     return 0;
}

