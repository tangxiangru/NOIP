#include <stdio.h>
int main(int argc, char *argv[])
{
    int x,y;
    scanf("%d%d",&x,&y);
    while(x!=y)
    {
        if(x>y) x=x/2;
        else y=y/2;
    }
    printf("%d\n",x);
    return 0;
}
