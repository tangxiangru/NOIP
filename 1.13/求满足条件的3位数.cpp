#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    int i,t;
    int x,y,z;
    int xx,yy,zz;
    cin>>n;
    for(i=100;i<1000;i++)  //检查每一个三位数，判断其是否符合要求
    {
        t=sqrt(i);
        if(t*t==i)//这个if语句的条件语句是判断i是否完全平方数 
        {//下面把i的各个位拆开来检查有否相同位。 
            x=i/100;
            y=(i-x*100)/10;
            z=i%10;
            xx=0;
            yy=0;
            zz=0;
            xx=(x==y);
            yy=(x==z);
            zz=(y==z);
            if(xx+yy+zz>=1)
            {
                n--;
                if(n==0)//当发现到第n个满足两个条件的数时停止。 
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
