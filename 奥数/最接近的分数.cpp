#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int gcd(int a,int b){
if(b==0)
return a;
return gcd(b,a%b);
}
int main(){
double n,a,b,max=-1;
int a1,b1;
scanf("%lf%lf%lf",&n,&a,&b);
double d=(double)a/b;
for(int i=2;i<=n;i++)
for(int j=1;j<i;j++)
if(gcd(i,j)==1){
double c=(double)j/i;
if(c<d){
if(max<c){
max=c;
a1=j,b1=i;
}
}
}
printf("%d %d",a1,b1);
return 0;
}
