#include "iostream"
using namespace std;
int main()
{
    int num[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>num[i][j];
        }
    }
    int m,n;
    cin>>m>>n;
    int tempn[5]={0};
    for(int i=0;i<5;i++)
    {
        tempn[i]=num[m-1][i];
    }
    for(int i=0;i<5;i++)
    {
        num[m-1][i]=num[n-1][i];
    }
    for(int i=0;i<5;i++)
    {
        num[n-1][i]=tempn[i];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(j!=4)
                cout<<num[i][j]<<" ";
            else
                cout<<num[i][j]<<endl;
        }
    }
    return 0;

