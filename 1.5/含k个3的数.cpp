#include "iostream"
#include "math.h"
using namespace std;
int main()
{
    string str;
    int k;
    cin>>str>>k;
    int sum=0;
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        if(str.at(i)=='3')
            count++;
        sum+=(str.at(str.length()-1-i)-48)*pow(10,i);
    }
//    cout<<sum<<" "<<count<<endl;
    if(sum%19==0&&count==k)
    {
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
