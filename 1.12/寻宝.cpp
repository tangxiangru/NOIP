#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=10000;
int mod=20123;
struct dqs
{
    int shu;
    bool ti;
}map[maxn][105];
int cnt[maxn];
inline int read()
{
    int x=0;
    char ch=getchar();
    while(ch>'9'||ch<'0') 
    {
        ch=getchar();   
    }
    while(ch>='0'&&ch<='9') 
    {
        x=x*10+ch-'0';
        ch=getchar();       
    }
    return x;
}
int main()
{
    bool flag;
    int n,m,wz;
    n=read();
    m=read();
//  scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)
    {
        map[i][j].ti=read();
        map[i][j].shu=read();
        if(map[i][j].ti==1)
            cnt[i]++;
    }
    int ans=0;
    int cs=1;
    wz=read();
    while(cs<n+1)
    {
        ans+=map[cs][wz].shu;
        ans=ans%mod;
        if(ans<0)
            ans+=mod;
        int lala=map[cs][wz].shu;
    //  cout<<lala<<" lala"<<endl;
        lala=lala%cnt[cs]+cnt[cs];
        while(lala)
        {
            if(map[cs][wz].ti==true)
                    lala--;
            if(lala==0)
                    wz=0;
        }
        cs++;
    }
    printf("%d\n",ans%mod);
    return 0;
}
