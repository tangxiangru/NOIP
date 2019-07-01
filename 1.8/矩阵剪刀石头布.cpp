#include<iostream>
#include<cstring>
using namespace std;
int r,c,n;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char a[2][110][110];
void work(int last/*滚动数组*/,int h/*行*/,int l/*列*/,char win/*目标字符，即可以更新它的字符*/)
{
    int now=(last+1)%2;
    int ok=0;
    for(int i=0;i<4;i++)
    {
        if(a[last][h+dx[i]][l+dy[i]]==win)  ok=1,a[now][h][l]=win;
        if(ok) break;//更新了便可退出 
    }
    if(!ok) a[now][h][l]=a[last][h][l];
}
int main()
{
    cin>>r>>c>>n;
    for(int i=1;i<=r;i++)
     for(int j=1;j<=c;j++)
      cin>>a[0][i][j];
    for(int k=1;k<=n;k++)
    {
        memset(a[k%2],'\0',sizeof(a[k%2]));//滚动数组要初始化
        for(int i=1;i<=r;i++)
         for(int j=1;j<=c;j++)
          switch(a[(k-1)%2][i][j])
          {
               case 'R':work((k-1)%2,i,j,'P');break;//解释：若这个格子为R，那要以这个格子的坐标为基准，在四周找能更新它的P 
               case 'S':work((k-1)%2,i,j,'R');break;
               case 'P':work((k-1)%2,i,j,'S');break;
          }
    }
    for(int i=1;i<=r;i++)
     {
         for(int j=1;j<=c;j++)
         cout<<a[n&1][i][j];
         cout<<endl;
     }      
}
