#include<bits/stdc++.h>
using namespace std;

int n,k,x,y,c,t;

int main()
{
cin>>k>>n;
while(k--)
{
cin>>x>>y;
c=min(min(x,n-x+1),min(y,n-y+1));
t=1+(n*n)-(n-2*(c-1))*(n-2*(c-1));
if(x==c)t+=(y-c);
else if(y==n-c+1)t+=(n-2*c+1)+(x-c);
else if(x==n-c+1)t+=(n-(c-1)*2)*2-2-y+(n-c+1);
else t+=(n-(c-1)*2)*3-3-x+(n-c+1);
cout<<t<<"\n";
}
return 0;
}
