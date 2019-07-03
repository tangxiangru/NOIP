#include<bits/stdc++.h>
using namespace std;
int f(int x){
int i=0;
while(x%5==0){
x/=5;
i++;
}
return i;
}
int t(int x){
int i=0;
while(x%2==0){
x/=2;
i++;
}
return i;
}
int main()
{
double d,g,e=0,j,a,b=0,c=0;
cin>>a>>b;
for(int i=a;i<=b;i++){
e+=f(i);
c+=t(i);
}
cout<<min(e,c);
}
