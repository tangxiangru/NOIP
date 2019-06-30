#include "iostream"
#include "iomanip"
using namespace std;
const int MAXLEN = 20;
int sum[MAXLEN];
//将阶乘结果存储在数组中
int* getFac(int n)
{
    //因为我们在函数体外需要使用这个一维数组，所以需要new
    int* result= new int[MAXLEN];
    for(int i=0;i<MAXLEN;i++)
    {
        result[i]=0;
    }
    int k=1;
    int C=0;
    result[0] = 1;
    //把大数字分来存储，每个数字不超过9999(这是我自己选定的数值也可以是其他值)，因此例如1928321312存储为192 2832 1312
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
    return result;

}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int* tmp = getFac(i);
        for(int i=0;i<MAXLEN;i++)
        {
            sum[i]+=*(tmp+i);
        }
        int C = 0;
        //阶乘相加，注意进位处理
        for(int i=0;i<MAXLEN;i++)
        {
            sum[i] = sum[i]+C;
            if(sum[i]>=10000)
            {
                C=sum[i]/10000;
                sum[i]=sum[i]%10000;
            }else
                C = 0;
        }
    }
    //输出结果
    bool startF = false;
    bool firstF = true;
    for(int i=MAXLEN;i>=0;i--)
    {
        if(sum[i])
            startF = true;
        if(startF) {
            if(firstF) {
                cout << sum[i];
                firstF = false;
            } else {
                cout.fill('0');
                cout << setw(4) << sum[i];
            }
        }
    }
}
