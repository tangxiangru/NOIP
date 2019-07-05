#include <stdio.h>

using namespace std;

int d[15][15];

int dp(int m,int n) {
    if(m==0||n==1) return 1;
    if(m<n) return dp(m,m);
    else
        return dp(m,n-1)+dp(m-n,n);
}

int main()
{
    int t,m,n;
    scanf("%d",&t);

    while(t--) {
        scanf("%d%d",&m,&n);

        int ans = dp(m,n);

        printf("%d\n",ans);

    }

    return 0;
}

