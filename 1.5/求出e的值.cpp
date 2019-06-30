#include "iostream"
#include "iomanip"
using namespace std;
double getFac(double n)
{
    if(n==1)
        return n;
    return n*getFac(n-1);
}
int main(void)
{
    double n,e=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        e+=1/getFac(i);
    }
    cout<<fixed<<setprecision(10)<<e<<endl;
}
