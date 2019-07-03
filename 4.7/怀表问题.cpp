#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<set>
#include<string.h>
#include<sstream>
using namespace std;
int n,k;
string a[100]={};
string nexts[4]={"LV","LL","VV","VL"};
int number[5]={};
typedef long long int h;
struct result{
int start;
int length;
int num[4];
long long int value;
result(int a,int b,int c,int d,int e,int f,h g){
start=a;
length=b;
num[0]=c;
num[1]=d;
num[2]=e;
num[3]=f;
value=g;
}
bool operator<(const result &b)const{
if(start==b.start&&length==b.length&&num[0]==b.num[0]&&num[1]==b.num[1]&&num[2]==b.num[2])
return num[3]<b.num[3];
else if(start==b.start&&length==b.length&&num[0]==b.num[0]&&num[1]==b.num[1])
return num[2]<b.num[2];
else if(start==b.start&&length==b.length&&num[0]==b.num[0])
return num[1]<b.num[1];
else if(start==b.start&&length==b.length)
return num[0]<b.num[0];
else if(start==b.start)
return length<b.length;
return start<b.start;
}
};
int code[100]={};
set<result> v;
h cloc(int length,int start){
h sum=0;
pair<set<result>::iterator,set<result>::iterator> p=v.equal_range(result(start,length,number[0],number[1],number[2],number[3],0));
if(p.first!=p.second)
return p.first->value;
if(length==0&&start==code['L'])
return 1;
if(length==0&&start!=code['L'])
return 0;
if(number[1]==0&&number[3]==0)
return 0;
for(int i=0;i<4;++i){
if(number[i]>=1&&code[nexts[i][0]]==start){
--number[i];
sum+=cloc(length-1,code[nexts[i][1]]);
++number[i];
}
}
v.insert(result(start,length,number[0],number[1],number[2],number[3],sum));
return sum;
}
int main(){
memset(code,0xff,sizeof(code));
code['L']=0;
code['V']=1;
while(cin>>n>>k){
memset(number,0,sizeof(number));
cin>>a[0];
for(int i=1;i<n+1;i++){
cin>>a[i];
if(a[i]=="LV")
++number[0];
else if(a[i]=="LL")
++number[1];
else if(a[i]=="VV")
++number[2];
else
++number[3];
}
h num;
if(a[0][0]=='L')
num=cloc(k,code[a[0][1]]);
else{
int temp=number[0];
number[0]=number[3];
number[3]=temp;
temp=number[1];
number[1]=number[2];
number[2]=temp;
num=cloc(k,!code[a[0][1]]);
}
if(num){
cout<<"YES"<<endl;
cout<<num<<endl;
}
else
cout<<"NO"<<endl;
}
}
