#include "iostream"
using namespace std;
//用一维数组存储AB的出拳序列
int A[100];
int B[100];
//返回1，Awin；返回0，平局，返回-1，Bwin
int result(int ANum,int BNum)
{
    switch (ANum)
    {
        case 0:
            if(BNum==0) return 0;
            else if(BNum == 2) return 1;
            else return -1;
        case 2:
            if(BNum==2) return 0;
            else if(BNum==5) return 1;
            else return -1;
        case 5:
            if(BNum==5) return 0;
            else if(BNum == 0) return 1;
            else return -1;
        default:
            return -2;
    }
}
int main() {
    int tryNum;
    cin >> tryNum;
    int Alen, Blen,ASum = 0,BSum =0;
    cin >> Alen >> Blen;
    for (int i = 0; i < Alen; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < Blen; i++)
    {
        cin >> B[i];
    }
    for(int i=0;i<tryNum;i++)
    {
        int temp = result(A[i%Alen],B[i%Blen]);
        if(temp==1)
            ASum++;
        if(temp==-1)
            BSum++;
    }
    if(ASum>BSum)
        cout<<"A";
    else if(ASum==BSum)
        cout<<"draw";
    else
        cout<<"B";
    return 0;
}

