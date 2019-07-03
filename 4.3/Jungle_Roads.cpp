#include<bits/stdc++.h>
using namespace std;

const int MAX=200;
int fa[30];
struct Node{
int x,y;
int w;
Node(){}
Node(int x,int y,int w):x(x),y(y),w(w){}
}tree[MAX];

int cmp(Node a,Node b){
return a.w<b.w;
}

char a,b,c;
int n,m,w,x,y,cnt=0;

int find(int x){
if(x==fa[x])
return x;
else
return fa[x]=find(fa[x]);
}

int ji,ans=0;
void kruskal(){
for(int i=1;i<=cnt;i++)
{
x=tree[i].x;
y=tree[i].y;
int fx=find(x);
int fy=find(y);
if(fx == fy)
continue;
else{
fa[fy]=fx;
ans+=tree[i].w;
ji--;
}
if(ji==1) break;
}
return ;
}

int main(){

while(scanf("%d",&n)&&n){
ans=0;
cnt=0;
memset(tree,0,sizeof(tree));
ji=n;
for(int i=1;i<=n;i++) fa[i]=i;//初始化；
for(int i=1;i<=n-1;i++)
{
cin>>a>>m;
for(int i=1;i<=m;i++)
{
cin>>b>>w;
int opa=a-'A'+1;
int opb=b-'A'+1;
cnt++;
tree[cnt]=Node(opa,opb,w);
}
}
sort(tree+1,tree+cnt+1,cmp);

kruskal();

printf("%d\n",ans);
}
return 0;
}
