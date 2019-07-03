#include <bits/stdc++.h>
using namespace std;
map<string,bool>b;
map<string,int>a;
struct node{
string a;
int step;
};
int i,n;string s,bs,es;
int main(){
cin>>bs>>es>>s;
while (cin>>s) a[s]=(++i);
a[es]=(++i);
b.clear();
b[bs]=true;
queue<node> q;
q.push((node){bs,1});
if (bs==es){
cout<<"1\n";
return 0;
}
while (!q.empty()){
node z=q.front();q.pop();
for(int i=0;i<z.a.size();i++)
for(char ch='a';ch<='z';ch++)
if (ch!=z.a[i]){
string ts=z.a;
ts[i]=ch;
if (a.count(ts)&&!b[ts]){
b[ts]=true;
if (ts==es){
cout<<z.step+1<<endl;
return 0;
}
q.push((node){ts,z.step+1});
}}}
cout<<"0\n";
return 0;
}
