#include "iostream"
using namespace std;
int main()
{
    int num[12];
    for(int i=0;i<12;i++)
    {
        cin>>num[i];
    }
    int money=300;
    int store=0;
    int flag=true;
    for(int i=0;i<12;i++)
    {
        if(money-num[i]>=0)
        {
            store+=(money-num[i])/100*100;
            money=money-(money-num[i])/100*100-num[i]+300;
            //cout<<store<<" "<<money<<endl;
        }else{
            cout<<"-"<<i+1;
            flag=false;
            break;//不加break会WA，因为如果接下来的月份如果有不够支出的情况会输出最大月份
        }
    }
    if(flag)
        cout<<store+store*0.2+money%300;//最后一个月可能剩下钱
    return 0;
}
