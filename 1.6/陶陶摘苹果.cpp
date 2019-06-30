#include "iostream"
using namespace std;
int main()
{
    int num[10];
    for(int i=0;i<10;i++)
    {
        cin>>num[i];
    }
    int high;
    cin>>high;
    int count=0;
    for(int i=0;i<10;i++)
    {
        if(high+30>=num[i])
            count++;
    }
    cout<<count;
    return 0;
}


