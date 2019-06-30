#include "iostream"
using namespace std;
int main()
{
    double sn=0;
    int K;
    cin>>K;
    int count=1;
    while(sn<=K)
    {
        sn+=1/(double)count;
        count++;
    }
    cout<<--count;
    return 0;
}
