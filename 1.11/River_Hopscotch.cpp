#include <stdio.h>
int river[50020];
int main()
{
    int l,r,n,m;
    int i,j,mid;
    int ans;
    scanf("%d%d%d",&ll,&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&river[i]);
    river[0]=0;
    river[n+1]=ll;
    l=0;
    r=ll+1;
    while(l+1<r)
    {
        mid=(l+r)/2;
        ans=0;
        i=0;
        while(i<=n)
        {
            j=i+1;
            while(river[j]-river[i]<mid&&j<=n+1)
                j++;
            ans+=j-i-1;//因为算的是间距，所以还要-1 
            i=j;
        }
        if(ans<=m) l=mid;
        else r=mid; 
    }
    printf("%d\n",l);
    return 0;
}
