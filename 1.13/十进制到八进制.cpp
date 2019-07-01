#include<iostream>
using namespace std;
int b[100];
int main(){
int a,i=1;
cin>>a;
do
{
b[i]=a%8;
a=a/8;
i++;
}
while(a!=0);
for(int j=i-1;j>=1;j--)
{
cout<<b[j];
}
return 0;
}
