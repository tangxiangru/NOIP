#include "iostream"
using namespace std;
int main()
{
    int m,n,num[100]={0};
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        m=m-num[i];
        if(m<0)
        {
            count++;
            m+=num[i];
        }
    }
    cout<<count;
    return 0;
}
