#include<stdio.h>
#include<math.h>
#define Pi 3.1415926//***************************//
double f1(double n)
{
    double a ,b=1;
    for(a=1;a<=n;a++)
    {
        b=b*a;
    }
    return b;
}

 main()
{
    int d=1;
    
    double a,b,i,e,c=3;
    printf("Input x:\n",a);
    scanf("%lf",&a);
    a=fmod(a,Pi);//fmod函数是求a与Pi整除的余数，加了这个便没有数据溢出了
    e=-a*a*a;
    
    b=a;
    do
    {
        
        i=e/f1(c);
        b=b+i;
        d++;
        e=-(e*a*a);
        c=c+2;
    }while(fabs(i)>=1e-5);
    printf("sin(x)=%.3f,count=%d\n",b,d-1);
    


}
