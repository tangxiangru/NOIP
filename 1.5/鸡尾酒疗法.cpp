#include "iostream"
#include "math.h"
#include "iomanip"
using namespace std;
int main()
{
    int count;
    cin>>count;
    double num[21];
    int num1,num2;
    for(int i=0;i<count;i++)
    {
        cin>>num1>>num2;
        num[i]=(double)num2/num1;
    }
    for(int i=0;i<count-1;i++)
    {
        if(num[i+1]-num[0]>0.05)
            cout<<"better"<<endl;
        else if(num[i+1]-num[0]<-0.05)
            cout<<"worse"<<endl;
        else
            cout<<"same"<<endl;
    }
    return 0;
}
