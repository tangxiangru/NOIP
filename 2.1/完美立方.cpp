#include<stdio.h>
int main()
{
    int a,b,c,d,N;
    int a3,b3,c3,d3;
    scanf("%d",&N); 
    for(a=2;a<=N;a++)
    {
        a3=a*a*a;
        for(b=2;b<=N;b++)
        {
            b3=b*b*b;
            if(a3<b3) break;
            for(c=b;c<=N;c++)
            {
                c3=c*c*c;
                if(a3<b3+c3)  break;
                for(d=c;d<=N;d++)
                {
                    d3=d*d*d;
                    if(a3==b3+c3+d3)
                    {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                    }
                }
            }
        }
    }
    return 0;
}
