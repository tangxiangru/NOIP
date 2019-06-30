#include "iostream"
using namespace std;
int main()
{
    int count;
    int time=0;
    int num[100];
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cin>>num[i];
    }
    int cmp;
    cin>>cmp;
    for(int i=0;i<count;i++)
    {
        if(cmp==num[i])
            time++;
    }
    cout<<time;
    return 0;
}

