#include "iostream"
using namespace std;
int get2Count(int num)
{
    int temp;
    int count = 0;
    while(num)
    {
        temp = num%10;
        num = num/10;
        if(temp==2)
        {
            count++;
        }
    }
    return count;
}
int main(void)
{
    int result=0;
    int num1,num2;
    cin>>num1>>num2;
    for(int i=num1;i<=num2;i++)
    {
        result+=get2Count(i);
    }
    cout<<result;
}
