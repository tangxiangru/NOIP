#include "iostream"
#include "iomanip"
using namespace std;
int main()
{
    int n,num1=0,num2=0,num3=0,num4=0,sum=0;
    int num[100];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        if(num[i]>=0&&num[i]<=18)
        {
            num1++;
        }else if(num[i]>=19&&num[i]<=35)
        {
            num2++;
        }else if(num[i]>=36&&num[i]<=60)
        {
            num3++;
        }else if(num[i]>=61)
        {
            num4++;
        }
    }
//    cout<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<endl;
    sum=num1+num2+num3+num4;
    cout<<fixed<<setprecision(2)<<num1*100/(double)sum<<"%"<<endl<<num2*100/(double)sum<<"%"<<endl<<num3*100/(double)sum<<"%"<<endl<<num4*100/(double)sum<<"%";
    return 0;
}
