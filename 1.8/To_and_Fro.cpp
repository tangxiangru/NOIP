#include<iostream>
#include<cstring>
using namespace std;
int n;
char a[201][21],b[201];
int main()
{
    cin>>n;
    cin>>b;
    int l=0,i=1,j=0;
    int p=1;
    while(l<strlen(b))//蛇形存储
    {
        if(p==1) j++;
        else if(p==2)  j--;
        if(j>n)
        {
            j=n;p=2;i++;
        }
        if(j<1)
        {
            j=1;p=1;i++;
        }
        a[i][j]=b[l];
        l++;
    }
    for(int m=1;m<=n;m++)
     for(int k=1;k<=i;k++)
      cout<<a[k][m];
}
