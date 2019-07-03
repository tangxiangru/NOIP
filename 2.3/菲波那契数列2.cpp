#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
int fibo[1000005]={0,1,1},a,n;
for(int i=3;i<=1000000;i++)fibo[i]=(fibo[i-1]+fibo[i-2])%1000;
cin>>a;
while(a--){
cin>>n;
cout<<fibo[n]<<endl;
}
return 0;
}
