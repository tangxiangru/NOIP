#include "iostream"
#include "math.h"
#include "iomanip"
using namespace std;
int main()
{
    double x,y;
    int num;
    int count;
    double sum=0;
    cin>>count;
    for(int i=0;i<count;i++)
    {
        cin>>x>>y>>num;
        sum+=2*(sqrt(pow(x,2)+pow(y,2))/50)+num*1.5;
    
    }
    cout<<ceil(sum);
    return 0;
}
