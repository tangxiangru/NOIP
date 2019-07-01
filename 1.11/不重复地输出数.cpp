#include <stdio.h>
#include <stdlib.h>
#define maxn 100010
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n;
    int i;
    int a[maxn];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    printf("%d ",a[0]);
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1]) continue;
        printf("%d ",a[i]);
    }
    return 0;
}
