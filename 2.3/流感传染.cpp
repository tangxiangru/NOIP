#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char a[100][100];
    int i,n,j,d,m,sum=0;
    freopen("5.in","r",stdin);
    //freopen("result.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cin>>m;
    /*调试性输出
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }*/

    for(d=2;d<=m;d++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='@')
                {
                    if(i+1<n&&a[i+1][j]=='.')
                      a[i+1][j]='!';
                    if(j-1>=0&&a[i][j-1]=='.')
                      a[i][j-1]='!';
                    if(j+1<n&&a[i][j+1]=='.')
                      a[i][j+1]='!';
                    if(i-1>=0&&a[i-1][j]=='.')
                      a[i-1][j]='!';
                }
            }
        }
        /*调试性输出
        cout<<endl<<"===========第"<<d<<"天================"<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }*/
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i][j]=='!')
                  a[i][j]='@';
            }
        }
    }
    sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]=='@')
              sum++;
        }
    }
    cout<<sum<<endl;
    return 0;
}
