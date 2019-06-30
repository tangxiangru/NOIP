#include "iostream"
using namespace std;
bool have7(int num)
{
    int temp;
    while(num)
    {
        temp = num%10;
        num = num/10;
        if(temp==7)
        {
            return true;
        }
    }
    return false;
}
bool divBy7(int num)
{
    if(num%7==0)
        return true;
    else
        return false;
}
int main(void)
{
    int result=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(!have7(i)&&!divBy7(i)) {
            result += i * i;
            cout<<i<<endl;
        }
    }
    cout<<result;
}
