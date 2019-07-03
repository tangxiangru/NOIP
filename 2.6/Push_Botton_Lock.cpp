#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
#define N 110
#define NN 100
typedef long long LL;

LL C[N][N],S[N][N],P[N];

void init()
{
    C[1][0]=C[1][1]=1;
    S[1][0]=0,S[1][1]=1;
    P[1]=1;
    for (int i=2;i<=NN;i++)
    {
      C[i][0]=C[i][i]=1;
      S[i][0]=0,S[i][i]=1;
      for (int j=1;j<i;j++)
      {
        C[i][j]=C[i-1][j-1]+C[i-1][j];
        S[i][j]=S[i-1][j-1]+j*S[i-1][j];
      }
      P[i]=P[i-1]*i;
    }
}

int main()
{
    init();
    int T,n;
    scanf("%d",&T);
    for (int e=1;e<=T;e++)
    {
      scanf("%d",&n);
      LL ans=0;
      for (int i=1;i<=n;i++)
      {
        LL h=0;
        for(int j=1;j<=i;j++)
          h+=S[i][j]*P[j];
        ans+=C[n][i]*h;
      }
      printf("%d %d %I64d\n",e,n,ans);
    }
    return 0;
}
