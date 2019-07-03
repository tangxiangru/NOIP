#include<iostream>
using namespace std;
int main()
{
int a[15]={0},num=0,t;
cin>>t;

while(t!=0)
{
num++;
a[num]=t;
cin>>t;
}

int ans=0;

for(int i=1;i<=num;i++)
for(int j=1;j<=num;j++)
if(2*a[i]==a[j])
ans++;
cout<<ans;

return 0;
}
