#include "iostream"
using namespace std;
int main()
{
    int num1[7]={0};
    int num2[7]={0};
    for(int i=0;i<7;i++)
    {
        cin>>num1[i]>>num2[i];
    }
    int max=0,maxpos=0;
    for(int i=0;i<7;i++)
    {
        if(max<(num1[i]+num2[i])){
            max=num1[i]+num2[i];
            maxpos=i+1;
        }
    }
    cout<<maxpos;
    return 0;
}
