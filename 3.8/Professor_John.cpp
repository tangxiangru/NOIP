#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

bool edge[27][27];
vector<int > graph[27];
bool flag;
priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > > ch;

void printans(){
while(!ch.empty()){
char a='A'+ch.top().first-1, b='A'+ch.top().second-1;
ch.pop();
printf("%c<%c\n", a, b);
}
}

void dfs(int src, int here){
if(!edge[src][here]&&src!=here)
{
flag=true;
ch.push(make_pair(src, here));
edge[src][here]=true;
}
for(int i=0;i<graph[here].size();i++)
dfs(src, graph[here][i]);
}

int main(){
int t, c=1, n;
cin>>t;
while(t--){
memset(edge, false, sizeof(edge));
for(int i=0;i<30;i++)
vector<int>().swap(graph[i]);
cin>>n;
string tmp;
for(int i=1;i<=n;i++){
cin>>tmp;
int a=tmp[0]-'A'+1, b=tmp[2]-'A'+1;
if(tmp[1]=='>') swap(a, b);
edge[a][b]=true;
graph[a].push_back(b);
}
cout<<"Case "<<c<<':'<<endl;
flag=false;
for(int i=1;i<=26;i++)
if(!graph[i].empty())
dfs(i, i);
if(!flag) cout<<"NONE"<<endl;
else printans();
c++;
}
return 0;
}
