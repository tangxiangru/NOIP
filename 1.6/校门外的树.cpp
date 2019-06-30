#include "iostream"
#include "iomanip"
using namespace std;
int main()
{
    int L,M;
    cin>>L>>M;
    int num1,num2;
    bool flag[10002]={false};//注意一维数组的长度
    for(int i=0;i<M;i++)
    {
        cin>>num1>>num2;
        for(int j=num1;j<=num2;j++)
            flag[j]=true;
    }
    int count=0;
    for(int i=0;i<=L;i++)
    {
        if(!flag[i])
        {
//            cout<<"i:"<<i<<endl;
            count++;
        }
    }
    cout<<count;
    return 0;
}
