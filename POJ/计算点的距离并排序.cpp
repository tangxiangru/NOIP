#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
struct dian
{
    int xx,yy,zz;
};
struct juLi
{
    dian a,b;
    double len;
};
int main()
{
    struct dian A[12];
    struct juLi B[50],TEMP;
    int n,i,j,t;
    int flag;
    freopen("4.in","r",stdin);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>A[i].xx>>A[i].yy>>A[i].zz;
    }
    t=0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            B[t].a=A[i];
            B[t].b=A[j];
            B[t].len=sqrt((B[t].a.xx-B[t].b.xx)*(B[t].a.xx-B[t].b.xx)+
                          (B[t].a.yy-B[t].b.yy)*(B[t].a.yy-B[t].b.yy)+
                          (B[t].a.zz-B[t].b.zz)*(B[t].a.zz-B[t].b.zz));
            t++;
        }
    }
    
    for(i=1;i<t;i++)
    {
        flag=1;
        for(j=0;j<t-i;j++) 
        {
            if(B[j].len<B[j+1].len) 
            { 
                flag=0;
                TEMP=B[j]; 
                B[j]=B[j+1]; 
                B[j+1]=TEMP; 
            }
        }
        if(flag)  break;  //if(flag==1)  break;
    }
    
    for(i=0;i<t;i++)
    {
        cout<<'('<<B[i].a.xx<<','<<B[i].a.yy<<','<<B[i].a.zz<<')';
        cout<<'-';
        cout<<'('<<B[i].b.xx<<','<<B[i].b.yy<<','<<B[i].b.zz<<')';
        cout<<'=';
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<B[i].len<<endl;
    }
    return 0;
}
