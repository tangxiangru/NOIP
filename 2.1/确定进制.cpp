#include<iostream>
#include<cstdio>

using namespace std;

int search2(int x){
int s=0,sum;
do{
sum=x%10;
if(sum>s)
s=sum;
x/=10;
}
while(x>0);
return s;
}

int search1(int x,int y,int z){
int a;
a=search2(x);
if(search2(y)>a)
a=search2(y);
if(search2(z)>a)
a=search2(z);
return a;
}

int work(int x,int y){
int s=1,sum=0;
do{
sum+=x%10*s;
s*=y;
x/=10;
}
while(x>0);
return sum;
}

int main(){
int i,k=0,n,m,l,n1,m1,l1,num=0;
cin>>n>>m>>l;
num=search1(n,m,l);
for(i=16;i>num;i--){
n1=work(n,i);
m1=work(m,i);
l1=work(l,i);
if(n1*m1==l1){
k=i;
}
}
cout<<k<<endl;
return 0;
}
