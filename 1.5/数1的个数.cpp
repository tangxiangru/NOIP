#include "iostream"
using namespace std;
int get1Count(int num)
{
    int temp;
    int count = 0;
    while(num)
    {
        temp = num%10;
        num = num/10;
        if(temp==1)
        {
            count++;
        }
    }
    return count;
}
int main(void)
{
    int result=0;
    int num;
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        result+=get1Count(i);
    }
    cout<<result;
}
