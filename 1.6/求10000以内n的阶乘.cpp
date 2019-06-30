#include "iostream"
#include "iomanip"
using namespace std;
int result[10000];
int main()
{
    int n;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }
    int k=1;
    int C=0;
    result[0] = 1;
    //把大数字分来存储，每个数字不超过9999，因此例如1928321312存储为192 2832 1312
    for(int i=1;i<=n;i++)//乘以1.....n
    {
        C=0;
        //从后向前处理
        for(int j=0;j<k;j++)
        {
            result[j]=(result[j])*i+C;
            //cout<<"#:"<<j<<" "<<result[0]<<" "<<result[1]<<endl;
            if(result[j]>=10000) {
                C = result[j] / 10000;
                result[j] = result[j] % 10000;
                if (j == k-1 ) {
                    k++;
                    result[j+1] = C;
                    break;
                }
            }else
                C= 0;
            //cout<<"@"<<C<<" "<<result[j]<<" "<<k<<endl;
        }
    }
    for(int i=k-1;i>=0;i--)
    {
        if(i==k-1)
            cout<<result[i];
        else {
            cout.fill('0');
            cout << setw(4) << result[i];
        }
    }
}
