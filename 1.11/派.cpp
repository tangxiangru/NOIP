#include <stdio.h>
#include <math.h>
#define maxn 10010

const double pi=acos(-1.0);
int main()
{
    double cakes[maxn];
    int c,friends;
    int i;
    double l,r;
    double minc=-1;
    double mid;
    int ans;
    scanf("%d%d",&c,&friends);
    friends++;
    for(i=0;i<c;i++)
    {
        scanf("%lf",&cakes[i]);
        cakes[i]=pow(cakes[i],2)*pi;
        if(minc<cakes[i]) minc=cakes[i];
    }
    l=0;
    r=minc;
    while(r-l>0.000001)
    {
        mid=(l+r)/2;
        ans=0;
        for(i=0;i<c;i++)
            ans+=cakes[i]/mid;
        if(ans>=friends) l=mid;
        else r=mid;
    }
    printf("%.3lf",l);
    return 0;
}
