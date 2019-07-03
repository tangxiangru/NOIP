#include<bits/stdc++.h>
using namespace std;
int main()
{
int x,a,b,c;
cin>>a>>b>>c;
for(x=2;x<=a;x++)
if((a%x==b%x)&&(b%x==c%x)){cout<<x<<endl;return 0;}
}
