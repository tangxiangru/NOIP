#include "iostream"
#include "iomanip"
using namespace std;
int main(void)
{
    float x;
    int n;
    float sum = 1;
    cin>>x>>n;
    for(int i=1;i<=n;i++)
    {
        sum=sum*x+1;
    }
    cout<<fixed<<setprecision(2)<<sum<<endl;
}
