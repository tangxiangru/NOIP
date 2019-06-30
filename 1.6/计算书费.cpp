#include "iostream"
#include "iomanip"
using namespace std;
int main()
{
    double money[10]={28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
    int num[10];
    for(int i=0;i<10;i++)
    {
        cin>>num[i];
    }
    double sum=0;
    for(int i=0;i<10;i++)
    {
//        cout<<num[i]<<" "<<money[i]<<endl;
        sum+=num[i]*money[i];
    }
    cout<<fixed<<setprecision(1)<<sum<<endl;
    return 0;
}

