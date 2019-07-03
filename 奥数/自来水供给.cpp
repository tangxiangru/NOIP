#include<iostream>
using namespace std;
int main(){
int n,num,sum=0;
cin>>n;
for(int i=n;i>=1;i--){
cin>>num;
if(i==n) //第一个村子只能用粗管；
sum+=num*8000;
else if(i>4) //大于4的村落，用粗管划算。
sum+=num*8000;
else if(i<=4) //i(i<=4)*2000小于等于8000，所以小于等于4的村落用细管划算。
sum+=num*i*2000;
}
cout<<sum<<endl;
return 0;
}//
