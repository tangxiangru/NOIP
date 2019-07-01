#include <stdio.h>
#include <stdlib.h>
#define maxn 100010
int a[maxn];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int found(int l,int r,int tg)
{
    int mid=(l+r)/2;
    while(l<r-1)
    {
        if(tg==a[mid]) return 1;
        else if(a[mid]>tg) r=mid;
        else l=mid;
        mid=(l+r)/2;
    }
    return 0;
}
int main()
{
    int n;
    int min;
    int i,j;
    int flag=0; 
    int sum;
    int n1,n2;
    int tg,l,r;
    scanf("%d",&n);
    scanf("%d",&a[0]);
    min=a[0];
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<min) min=a[i];
    }
    qsort(a,n,sizeof(int),cmp); //方便二分 
    scanf("%d",&sum);
    if(n==1) flag=0;
    else
    { 
         j=0;
        while(j<n)
         {
            tg=sum-min;
            if(found(j,n,tg))
            {
                flag=1;
                n1=min;//a[j]==min
                n2=tg;
                break;
            }
            else
                min=a[++j];
        }  
    }
    if(flag==0) printf("No\n");
    else printf("%d %d\n",n1,n2);
    return 0;
}
