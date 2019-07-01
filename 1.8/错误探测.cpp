#include<iostream>
using namespace std;
int h[101],l[101];
int n;
int x,y,dx,dy;//x统计和为奇数的行的总数，y统计列，dx为第一个出现行为奇数的行号，dy为列号
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
      for(int j=1;j<=n;j++) 
        {
             int x;
             cin>>x;
             h[i]+=x;
             l[j]+=x;
        }
    for(int i=1;i<=n;i++)
     {
         if(h[i]&1) x++,dx=i;
        if(l[i]&1) y++,dy=i;
     }
    if(x==1&&y==1) cout<<dx<<' '<<dy;
    else if(x>0||y>0) cout<<"Corrupt";
    else cout<<"OK";
}
