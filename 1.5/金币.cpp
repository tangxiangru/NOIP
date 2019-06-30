#include "iostream"
#include "math.h"
using namespace std;
int step[10001];//step[i]存储第i天总共获取的金币数
int getCoins(int num)
{
    int coin = 1;
    step[1] = 1;
    int index = 2;
    while(index<=num)
    {
        coin++;
        for(int j=1;j<=coin;j++)
        {
            //动态规划的思想
            step[index]=step[index-1]+coin;
            index++;
 
        }
    }
    return step[num];
}
int main()
{
    int num;
    cin>>num;
    cout<<getCoins(num);
}
