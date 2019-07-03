#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
int result;
string pick;
while(cin>>result>>pick,result,pick!="END"){
string ans="AAAAA";
int len=pick.length();
for(int i=0;i<len;++i)
for(int j=i+1;j<len;++j)
for(int k=j+1;k<len;++k)
for(int s=k+1;s<len;++s)
for(int t=s+1;t<len;++t){
int num[5];
num[0]=pick[i]-'A'+1;
num[1]=pick[j]-'A'+1;
num[2]=pick[k]-'A'+1;
num[3]=pick[s]-'A'+1;
num[4]=pick[t]-'A'+1;
int c=0;
while(c<120){
if(num[0]-num[1]*num[1]+num[2]*num[2]*num[2]-num[3]*num[3]*num[3]*num[3]+num[4]*num[4]*num[4]*num[4]*num[4]==result){
string temp;
for(int i=0;i<5;++i)
temp+=num[i]-1+'A';
ans=max(temp,ans);
}
++c;
next_permutation(num,num+5);
}
}
if(ans=="AAAAA")
cout<<"no solution"<<endl;
else
cout<<ans<<endl;
}
}

