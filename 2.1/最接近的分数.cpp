#include<iostream>
#include<cstdio>
#include<cstring>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;


int gcd(int a,int b) {
return b==0?a:gcd(b,a%b);
}

int main(){
int n,a,b,maxxi,maxxj;
double maxx=0;
cin>>n>>a>>b;
for(int i=1;i<=n;i++){
for(int j=1;j<i;j++){
if((j*1.0/i)<(a*1.0/b)){
if(j*1.0/i>maxx){
maxx=j*1.0/i;maxxi=i/gcd(i,j);maxxj=j/gcd(i,j);
}
}
}
}
cout<<maxxj<<" "<<maxxi;
}
