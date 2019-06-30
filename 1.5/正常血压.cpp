#include "iostream"
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num1,num2;
    int time=0,temp=0;
    for(int i=0;i<n;i++)
    {
        cin>>num1>>num2;
        if(num1>=90&&num1<=140&&num2>=60&&num2<=90)
        {
            temp++;
        }else
        {
            temp=0;
        }
        if(time<temp)
            time=temp;
    }
    cout<<time;
}
