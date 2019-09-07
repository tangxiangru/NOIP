#include<iostream>
using namespace std;
void main()
{    
    int n,i,j,sum1=0,sum2=0,a[100][100];
    cout<<"请输入矩阵的长度n:";cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(i==j) sum1+=a[i][j];
            if(i+j==n-1) sum2+=a[i][j];
        }
        cout<<"对角线1元素之和"<<sum1<<endl;
        cout<<"对角线2元素之和"<<sum2<<endl;
}











#include <iostream>
int main()
{ int i,j,s1=0,s2=0,s=0,a[5][5];
for(i=0; i<5; i++)
for(j=0; j<5; j++)
scanf("%d",&a[i][j]);
for(s1=s2=s=i=0; i<5; i++)
{ s1+=a[i][i];
s2+=a[i][4-i];
if(i%2==0)
{ s+=a[i][i];
if(i!=2)
s+=a[i][4-i];
}
}
printf("主对角线之和=%d\n",s1);
printf("次对角线之和=%d\n",s2);
printf("对角线行、列下标均为偶数元素之和=%d\n",s);
return 0;
}
