#include<iostream>
using namespace std;
struct person
{
    int weight;
    char name;
};
int main()
{
    int a[4]={0};//int z,q,s,l;
    int flag1,flag2,flag3;
    int i,j,flag;
    struct person b[4],t;
    for(a[0]=10;a[0]<=50;a[0]=a[0]+10)
    {
        for(a[1]=10;a[1]<=50;a[1]=a[1]+10)
        {
            if(a[0]==a[1]) continue;
            for(a[2]=10;a[2]<=50;a[2]=a[2]+10)
            {
                if(a[2]==a[0]||a[2]==a[1]) continue;
                for(a[3]=10;a[3]<=50;a[3]=a[3]+10)
                {
                    if(a[3]==a[0]||a[3]==a[1]||a[3]==a[2]) continue;
                    flag1=0;flag2=0;flag3=0;
                    if(a[0]+a[1]==a[2]+a[3]) flag1=1;
                    if(a[0]+a[3]>a[2]+a[1]) flag2=1;
                    if(a[0]+a[2]<a[1]) flag3=1;
                    if(flag1+flag2+flag3==3)
                    {
                        for(i=0;i<4;i++)
                        {
                            b[i].weight=a[i];
                        }
                        b[0].name='z';
                        b[1].name='q';
                        b[2].name='s';
                        b[3].name='l';
                        //下面是对数组b进行的冒泡排序
                        for(i=1;i<4;i++)
                        {
                            flag=1;
                            for(j=0;j<4-i;j++)
                            {
                                if(b[j].weight<b[j+1].weight)
                                {
                                    flag=0;
                                    t=b[j];
                                    b[j]=b[j+1];
                                    b[j+1]=t;
                                }
                            }
                            if(flag) break; //if(flag==1) break;
                        }
                        for(i=0;i<4;i++)
                        {
                            cout<<b[i].name<<' '<<b[i].weight<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
