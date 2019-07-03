#include<iostream>
#include<cmath>
using namespace std;
int getgcd(int a, int b)
{
if (a == 0) return b;
if (b == 0) return a;
if (!(a & 1) && !(b & 1))
return getgcd(a>>1, b>>1)<<1;
else if (!(b & 1))
return getgcd(a, b>>1);
else if (!(a & 1)) return getgcd(a>>1, b);
else return getgcd(abs(a - b), min(a, b));
}
int getlcm(int a,int b){
return a*b/getgcd(a,b);
}
bool empty(double a){
if(a-int(a)==0)
return true;
else
return false;
}
int main(){
double k,starta,startb,k2,k3,g2,g3;
cin>>k>>starta>>startb>>k2>>k3>>g2>>g3;
k/=2;
double g1=(startb-starta)/2;
double temp=double(getlcm(2*k,k2));
temp=double(getlcm(temp,k3));
for(double i=max(g2,g3);i<=2*temp;++i){
if((empty((i-g1)/k))&&(empty((i-g2)/k2))&&(empty((i-g3)/k3))){
cout<<i<<endl;
return 0;
}
}
cout<<"no answer"<<endl;
}
