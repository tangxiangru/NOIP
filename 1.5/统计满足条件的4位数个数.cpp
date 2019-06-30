#include "iostream"
using namespace std;
int main()
{
    int count;
    cin>>count;
    int num=0;
    int n;
    for(int i=0;i<count;i++)
    {
        cin>>n;
        int d1=n%10;
        int d2=(n%100)/10;
        int d3=(n%1000)/100;
        int d4=n/1000;
//        cout<<d1<<" "<<d2<<" "<<d3<<" "<<d4<<endl;
        if(d1-d4-d3-d2>0)
            num++;
    }
    cout<<num;
    return 0;
}
