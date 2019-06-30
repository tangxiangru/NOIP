#include "iostream"
#include "iomanip"
using namespace std;
int main()
{
    int count;
    int num[100];
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cin>>num[i];
    }
    int n=count;
    int temp = count-1;
    if(count%2==0)
        count=count/2;
    else
        count=(count-1)/2;
    for(int i=0;i<count;i++)
    {
        int m;
        m=num[i];
        num[i]=num[temp];
        num[temp]=m;
        temp--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}

