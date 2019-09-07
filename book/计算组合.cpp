#include <stdio.h>
int f(int n,int m)
{
    if(n<m){
        return 0;
    }
    if (n==m) {
        return 1;
    }
    if (m==0) {
        return 1;
    }
    return f(n-1,m-1) + f(n-1,m);
}
int main(int argc, const char * argv[])
{

    int n,m;
    printf("从n个球中取出m个：");
    scanf("%d,%d",&n,&m);
    printf("%d\n",f(n,m));
    return 0;
}
