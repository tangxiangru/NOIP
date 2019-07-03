#include<bits/stdc++.h>
using namespace std;
int a,b,c,cura,curb,head=0,tail=0;
string op[6]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
struct Node
{ int x,y,front,step,state;
}q[10000];
int vis[101][101];
void print(int x)
{
if(q[x].front!=-1)
print(q[x].front);
else return;
cout<<op[q[x].state]<<endl;
}
int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int main()
{ scanf("%d%d%d",&a,&b,&c);
if(c%gcd(a,b)!=0)
printf("impossible\n");
q[tail].x=0,q[tail].y=0,q[tail].front=-1,q[tail++].step=0;
vis[0][0]=1;
while(head<tail)
{
if(q[head].x==c||q[head].y==c)
{ printf("%d\n",q[head].step);
print(head);
return 0;
}
for(int i=0;i<6;i++)
{
cura=q[head].x;
curb=q[head].y;
if(i==0){cura=a;}
else if(i==1){curb=b;}
else if(i==2){cura=0;}
else if(i==3){curb=0;}
else if(i==4){(b-curb>=cura)?(curb+=cura,cura=0):(cura-=b-curb,curb=b);}
else{a-cura>=curb?(cura+=curb,curb=0):(curb-=a-cura,cura=a);}
if(vis[cura][curb])continue;
vis[cura][curb]=1;
q[tail].state=i;
q[tail].x=cura,q[tail].y=curb,q[tail].front=head,q[tail++].step=q[head].step+1;
}
head++;
}
return 0;
}
