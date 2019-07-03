#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>//binary_search
using namespace std;
int qiu(int a,int b,int n) {
if(n==0)
return a+b;
else
return qiu(a,a+b,n-1)+qiu(a+b,b,n-1)-a-b;
}
int main() {
int x,y,n;
cin>>x>>y>>n;
cout<<qiu(x,y,n);
return 0;
}
