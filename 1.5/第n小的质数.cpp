#include "iostream"
#include "math.h"
using namespace std;
/*质数定义为在大于1的自然数中，除了1和它本身以外不再有其他因数的数称为质数。*/
bool isPrime(int num)
{
    if(num == 2)
        return true;
    int tmp = sqrt(num);
    for(int i=2;i<=tmp;i++)
    {
        if(num%i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int count = 0;
    for(int i=2;i<=1000000000;i++)
    {
        if(isPrime(i))
        {
            count++;
        }
        if(count>=n) {
            cout<<i;
            return 0;
        }
    }
}
