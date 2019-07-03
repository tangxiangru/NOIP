#include<iostream>
#include<iomanip>
using namespace std;
int main() {
long double x,y,a,b,n;
cin>>x>>y>>a>>b;
n=(a*b-x*y)/(b-y);
cout<<fixed<<setprecision(2)<<n;
}
