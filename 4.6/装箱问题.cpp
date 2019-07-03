#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a[6];

bool Read()
{
for(int i=0;i<6;i++)
cin>>a[i];
if(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]==0)return false;
else return true;
}

int main()
{
while(Read()){
int Ans=a[5];

a[0]-=a[4]*11;
Ans+=a[4];

for(int i=0;i<a[3];i++)
if(a[1]>=5)a[1]-=5;
else a[0]-=(5-a[1])*4,a[1]=0;
Ans+=a[3];

while(a[2]>0){
if(a[2]>3)a[2]-=4;
else if(a[2]==3){
if(a[1]==0)a[0]-=9;
else a[1]--,a[0]-=5;
a[2]=0;
}
else if(a[2]==2){
if(a[1]>=3)a[1]-=3,a[0]-=6;
else a[0]-=(3-a[1])*4+6,a[1]=0;
a[2]=0;
}
else if(a[2]==1){
if(a[1]>=5)a[1]-=5,a[0]-=7;
else a[0]-=(5-a[1])*4+7,a[1]=0;
a[2]=0;
}
Ans++;
}

while(a[1]>0){
if(a[1]>=9)a[1]-=9;
else a[0]-=(9-a[1])*4,a[1]=0;
Ans++;
}

if(a[0]>0)Ans+=ceil(a[0]/36.0);cout<<Ans<<endl;
}
return 0;
}
