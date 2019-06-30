#include "iostream"
using namespace std;
int main()
{
    int num;
    cin>>num;
    while(num>=10)
    {
        cout<<num%10<<" ";
        num=num/10;
    }
    cout<<num;
    return 0;
}
