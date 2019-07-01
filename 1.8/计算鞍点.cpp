#include<iostream>
using namespace std;
int a[6][6];
bool ok;
int main()
{
    for(int i=1;i<=5;i++)
     for(int j=1;j<=5;j++)
            cin>>a[i][j];
    for(int i=1;i<=5;i++)//枚举每一行 
     {
          int max_h=-0x7fffffff,k=0;//max_h，当前行的最大值；k，max_h所在列 
          for(int j=1;j<=5;j++)
            if(a[i][j]>max_h)
             {
                 max_h=a[i][j];k=j;
            }
         int min_l=0x7fffffff,q=0;//min_l，第k列的最小值；q，min_l所在行 
         for(int l=1;l<=5;l++)
          if(a[l][k]<min_l) 
          {
                min_l=a[l][k];q=l;
          }
        if(q==i) 
        {
            cout<<i<<' '<<k<<' '<<a[i][k];
            return 0;
        }
     }
    cout<<"not found";
}
