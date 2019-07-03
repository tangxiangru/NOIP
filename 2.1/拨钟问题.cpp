#include<bits/stdc++.h>
using namespace std;
#include<iostream>
using namespace std;
int main()
{
std::ios::sync_with_stdio(false);
int z[10],i[10],sum;
for(int j=1;j<=9;j++)
cin>>z[j];
for(i[1]=0;i[1]<4;i[1]++)
for(i[2]=0;i[2]<4;i[2]++)
for(i[3]=0;i[3]<4;i[3]++)
for(i[4]=0;i[4]<4;i[4]++)
for(i[5]=0;i[5]<4;i[5]++)
for(i[6]=0;i[6]<4;i[6]++)
for(i[7]=0;i[7]<4;i[7]++)
for(i[8]=0;i[8]<4;i[8]++)
for(i[9]=0;i[9]<4;i[9]++)
{
sum=0;
sum+=(z[1]+i[1]+i[2]+i[4])%4;
sum+=(z[2]+i[1]+i[2]+i[3]+i[5])%4;
sum+=(z[3]+i[2]+i[3]+i[6])%4;
sum+=(z[4]+i[1]+i[4]+i[5]+i[7])%4;
sum+=(z[5]+i[1]+i[3]+i[5]+i[7]+i[9])%4;
sum+=(z[6]+i[3]+i[5]+i[6]+i[9])%4;
sum+=(z[7]+i[4]+i[7]+i[8])%4;
sum+=(z[8]+i[5]+i[7]+i[8]+i[9])%4;
sum+=(z[9]+i[6]+i[8]+i[9])%4;
if(sum==0)
{
for(int j=1;j<=9;j++)
while(i[j]--)
cout<<j<<" ";
return 0;
}
}
return 0;
}
