#include<iostream>
using namespace std;
int gz(int n){
int a[10]={6,2,5,5,4,5,6,3,7,6};
int m=n,ans=0;
do{
ans+=a[m%10];
m/=10;
}
while(m);
return ans;
}
int main(){
int n,ans=0;
cin>>n;
n-=4;
for(int i=0;i<=711;i++)
for(int j=0;j<=711;j++)
if(gz(i)+gz(j)+gz(j+i)==n)
ans++;
cout<<ans;
return 0;
}
