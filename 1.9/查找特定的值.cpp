
#include "iostream"
using namespace std;
int main()
{
    int n;
    int num[10002];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int cmpn;
    cin>>cmpn;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(cmpn==num[i])
        {
            cout<<i+1;
            flag=false;
            break;
        }
    }
    if(flag)
        cout<<"-1";
    return 0;
}
