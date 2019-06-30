#include "iostream"
using namespace std;
int main()
{
    string str;
    cin>>str;
    bool isZero=false;
    bool flag=false;
    if(str=="0")
        isZero=true;
    if(str.at(0)=='-')
    {
        cout<<"-";
        flag=true;
    }
    bool zeroF=true;
    int index=0;
    if(flag)
        index++;
    for(int i=0;i<str.length()-index;i++)
    {
        if(isZero)
        {
            cout<<str.at(str.length()-1-i);
        }
        else
        {
            if(str.at(str.length()-1-i)!='0')
            {
                cout<<str.at(str.length()-1-i);
                zeroF=false;
            }
            else
            {
                if(zeroF)
                    continue;
                else
                    cout<<str.at(str.length()-1-i);
            }
        }
    }
    return 0;
}
