#include<bits/stdc++.h>
using namespace std;
int main()
{
    string q,p,r; int l1,l2,l3,a1=0,a2=0,a3=0;
    cin>>q>>p>>r;
    l1=q.length();
    l2=p.length();
    l3=r.length();
    int maxx=0;
    for(int i=0;i<=l1-1;i++) 
    {
        int t=q[i]-'0';
        maxx=max(t,maxx);
    }
    for(int i=0;i<=l2-1;i++) 
    {
        int t=p[i]-'0';
        maxx=max(t,maxx);
    }
    for(int i=0;i<=l3-1;i++) 
    {
        int t=r[i]-'0';
        maxx=max(t,maxx);
    }
    for(int i=maxx+1;i<=16;i++)
    {
        a1=0;a2=0;a3=0;
        int x=1;
        for(int j=l1-1;j>=0;j--) { a1+=(q[j]-'0')*x; x*=i;}x=1;
        for(int j=l2-1;j>=0;j--) { a2+=(p[j]-'0')*x; x*=i;}x=1;
        for(int j=l3-1;j>=0;j--) { a3+=(r[j]-'0')*x; x*=i;}
        if(a3==a1*a2) 
        {
          cout<<i;return 0;
        }
        else
        if(i==16) 
        {
          cout<<0;return 0; 
        }
    }

}
