#include<cstdio>
#include<iostream>
#include<set>
#include<cmath>
using namespace std;
set<pair<int,int> > data;
void pd(int id,int power){
set<pair<int, int> >::iterator pos,pre,be;
pos=data.find(make_pair(power,id));
be=data.end();
be--;
cout<<id<<" ";
if(pos==data.begin()){ // 相同大小按输入顺序排序,输入id有序时可以 否则会出错;
pos++;
cout<<pos->second;
}
else if(pos==be){ //该情况应该不会出现;
pos--;
cout<<pos->second;
}
else{
be=pos;pre=pos;
be++;pre--;
int tp1=abs(power - pre->first),tp2=abs(power - be->first);
if(tp1>tp2){
int minid=be->second;
while(be!=data.end()){
be++;
if(power - be->first == tp2){
if(be->second <minid)
minid=be->second;
}
else break;
}
cout<<minid;
}
else if(tp1<tp2){
int minid=pre->second;;
while(pre!=data.begin()){
pre--;
if(power - pre->first ==tp1){
if(pre->second < minid )
minid=pre->second;
}
else break;
}
cout<<minid;
}
else if(tp1==tp2){
int minid=min(pre->second,be->second);
while(pre!=data.begin()){
pre--;
if(power - pre->first ==tp1){
if(pre->second < minid )
minid=pre->second;
}
else break;
}
while(be!=data.end()){
be++;
if(power - be->first == tp2){
if(be->second <minid)
minid=be->second;
}
else break;
}
cout<<minid;
}
}
cout<<endl;
}
int main(){
data.insert(make_pair(1000000000,1));
int n,id,power;
cin>>n;
while(n--){
cin>>id>>power;
data.insert(make_pair(power,id));
pd(id,power);
}
return 0;
}

