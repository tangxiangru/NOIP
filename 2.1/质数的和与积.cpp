#include <bits/stdc++.h>
using namespace std;
int work(int m){
int i;
if(m==2)return 1;
for(i=2;i<=sqrt(m);i++){
if(m%i==0)return 0;
}
return 1;
}

int main(){
int n,i,max=-123456789;
cin>>n;
for(i=2;i<=n;i++){
if(work(i)&&work(n-i))
if(max<(n-i)*i)
max=(n-i)*i;
}
cout<<max;
return 0;
}
