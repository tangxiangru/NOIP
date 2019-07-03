#include<iostream>
#define fx(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int ct[205];
int ctnow[205];
int a[200005],b[200005];
int main(){
int n,k,p;
cin>>n>>k>>p;
int sum=0;
fx(i,1,n)cin>>a[i]>>b[i];
fx(i,1,n){
sum+=ct[a[i]];
ctnow[a[i]]++;
if(b[i+1]<=p||b[i]<=p)fx(j,0,k-1)ct[j]=ctnow[j];
}
cout<<sum;
return 0;
}
