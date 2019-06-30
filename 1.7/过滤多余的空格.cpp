#include <stdio.h>
#include <stdlib.h>
#define N 210
int main()
{
    char a[N];
    int i,j;
    gets(a);
    for(i=0; a[i]!='\0'; i++)
        if(a[i]==' '&&a[i+1]==' ')
        {
            if(a[i+2]!=' ')
            {
                printf(" ");
                i++;
            }
            else
                i++;
        }
        else
            printf("%c",a[i]);
    return 0;
}
