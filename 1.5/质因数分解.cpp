#include "iostream"
#include "math.h"
using namespace std;
bool isPrime(int num)
{
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}
int main()
{
    int num;
    cin>>num;
    //从小到大找，最后输出num/i，如果从大到小找输出i会超时
    for(int i=2;i<=sqrt(num);i++)
    {
        if(num%i==0&&isPrime(i))
        {
            cout<<num/i;
            break;
        }
    }
}
