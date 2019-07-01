#include<iostream>
using namespace std;
struct person
{
    int n;//饭量或者断言数量
    char name;//名字 
};
int main()
{
    int a,b,c;//三者的范围都是1~3，这里把a、b、c的值看作他们的饭量（不一定要用1~3，只要能区分出三个数的大小就行了）
    //当然，也可以换一下思路，用a、b、c表示饭量排名
    int A,B,C;//表示断言正确的数量 
    struct person x[3],y[3],t;
    int i,j,flag;
    for(a=0;a<3;a++)
    {
        for(b=0;b<3;b++)
        {
            for(c=0;c<3;c++)
            {
                A=(b>a)+(c==a);
                B=(a>b)+(a>c);
                C=(c>b)+(b>a);
                /*假如三个人的饭量不会相等、三个人的断言正确数量也不会相等，
                下面就判断a+A、b+B、c+C是否都相等，都等于3就行了。
                但是这个题目，三个人饭量可能相等，断言正确数量也可能一样，必需用其他方式*/ 
                //下面把a、b、c、A、B、C分别放到数组x、y当中。 然后对x、y数组进行排序
                x[0].n=a;x[0].name='A';
                x[1].n=b;x[1].name='B'; 
                x[2].n=c;x[2].name='C';
                y[0].n=A;y[0].name='A';
                y[1].n=B;y[1].name='B'; 
                y[2].n=C;y[2].name='C';
                //对x数组按元素的饭量从大到小排序，对y数组按元素的断言正确数量从小到大排序
                for(i=1;i<3;i++)
                {
                    flag=1;
                    for(j=0;j<3-i;j++) 
                    {
                        if(x[j].n<x[j+1].n)
                        {
                            flag=0;
                            t=x[j];
                            x[j]=x[j+1];
                            x[j+1]=t;
                        }
                    }
                    if(flag) break; //if(flag==1) break;
                }
                
                for(i=1;i<3;i++)
                {
                    flag=1;
                    for(j=0;j<3-i;j++) 
                    {
                        if(y[j].n>y[j+1].n)
                        {
                            flag=0;
                            t=y[j];
                            y[j]=y[j+1];
                            y[j+1]=t;
                        }
                    }
                    if(flag) break; //if(flag==1) break;
                }
                //从头到尾检查x和y数组每一个元素对应的是否是同一个人 
                for(i=0;i<3;i++)
                {
                    if(x[i].name!=y[i].name) break;
                }
                if(i==3)
                {//输出结果 
                    for(i=2;i>=0;i--)
                        cout<<x[i].name;
                    cout<<endl;
                }
            }
        }
    }
    return 0;
}
