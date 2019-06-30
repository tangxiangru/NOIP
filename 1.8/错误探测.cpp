#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1001][1001];
int ouhang[1001];
int oulie[1001];
int cx,cy;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            ouhang[i]=(a[i][j]+ouhang[i])%2;
            oulie[j]=(a[i][j]+oulie[j])%2;
        }
    }
    int i1,j1;
    int toth,totz;
    for (int i=1;i<=n;++i)
    {
        if (ouhang[i]==1) i1=i;
        if (oulie[i]==1) j1=i;
        toth+=ouhang[i];
        totz+=oulie[i];
    }
    if (toth==0&&totz==0)cout<<"OK"<<endl;
    else if (toth==1&&totz==1)cout<<i1<<" "<<j1<<endl;
    else cout<<"Corrupt";

    return 0;
}
