#include "iostream"
#include "math.h"
#include "iomanip"
/*
 64位机下  int 4字节 ,long int 8字节
 */
using namespace std;
int main()
{
    long int num;//这里用int会Output Limit Exceeded
    cin>>num;
    if(num==1)
    {
        cout<<"End";
    }else{
        while(num!=1){
            if(num%2==0)
            {
                num=num/2;
                cout<<num*2<<"/2="<<num<<endl;
            }else{
                cout<<num<<"*3+1=";
                num=num*3+1;
                cout<<num<<endl;
            }
        }
        cout<<"End";
    }
    return 0;
}
