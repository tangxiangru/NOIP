#include "iostream"
using namespace std;
int result[30];
bool getDiv(string Num,int divNum,int Len)
{
    for(int i=0;i<Num.length();i++)
    {
        result[i]=Num[i]-'0';
    }
    int C = 0;
    //从高位到低位依次除以被除数，并将余数算进下一位
    for(int i=0;i<Len;i++)
    {
        result[i]=result[i]+10*C;
        C=result[i]%divNum;
    }
    //如果到个位有余数，说明不能被整除
    if(C==0)
        return true;
    else
        return false;
}

int main()
{
    string Num;
    cin>>Num;

    int haveDivNum = false;
    int startOut = true;
    for(int i=2;i<10;i++) {
        if(getDiv(Num,i, Num.length()))
        {
            haveDivNum = true;
            if(startOut) {
                cout << i;
                startOut = false;
            }else
                cout<<" "<<i;
        }
    }
    if(!haveDivNum)
        cout<<"none";
}
