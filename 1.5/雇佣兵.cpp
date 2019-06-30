#include "iostream"
#include "iomanip"
using namespace std;
int main(void)
{
    int M,N,X;
    cin>>M>>N>>X;
    //初始状态
    int fight = N;
    int current_M = 0;
    while(1)
    {
        if(X*fight >= M)
        {
            X-=(M+fight-1)/fight;
            current_M+=M;
        }//循环结束条件：能量不够补充，说明战斗结束
        else
        {
            break;
        }
        //参与战斗
        fight += M / fight;
        current_M = 0;
    }
    cout<<fight;
}
