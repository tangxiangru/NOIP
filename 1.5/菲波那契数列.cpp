#include "iostream"
#include "math.h"
#include "iomanip"
using namespace std;
int main()
{
    int num1=1,num2=1;
    int k;
    cin>>k;
    if(k<=2)
        cout<<"1";
    else{
        for(int i=0;i<k-2;i++)
        {
            int temp=num1+num2;
            num1=num2;
            num2=temp;
        }
    cout<<num2;
    }
    return 0;
}
