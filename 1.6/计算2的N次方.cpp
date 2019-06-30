#include "iostream"
using namespace std;
//一维数组存储每位数字
int result[20]={0};
int main()
{
    int N;
    cin>>N;
    result[0] = 1;
    //存储当前被乘数有效位数
    int Len = 1;
    for(int i=0;i<N;i++)//处理N次*2
    {
//        cout<<Len<<endl;
        //对每位做乘2处理
        for(int j=0;j<Len;j++)
        {
            result[j] = result[j]*2;
        }
//        for(int j=0;j<Len;j++)
//        {
//            cout<<"#"<<result[j]<<endl;
//        }
        //对每位超过10的，做-10并进位处理
        for(int j=0;j<Len;j++)
        {
            if(result[j]>=10)
            {
                result[j]-=10;
                result[j+1]++;
                //有进位时，考虑更新被乘数有效位数
                Len = (j+1+1)>Len?(j+1+1):Len;
            }
        }
    }
    //输出
    for(int i=Len-1;i>=0;i--)
    {
        cout<<result[i];
    }
}
