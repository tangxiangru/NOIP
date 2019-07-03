#include <iostream>

using namespace std;
int a[30010];
int n;

int vail(int time)
{
int pos,np,nt,fl=0;
pos=1;nt=0;np=0;
for(int i=0;i<n;i++)
{
if(nt+(a[i]-pos)*20>time)
{
if(fl)
{
nt+=10;
}
else fl=1;//每停下一次加上电梯等待时间

if(nt+(a[i]-pos)*4>time) return 0;//加上最短的时间都没发完成，TIME不可行

for(np=a[i];(np-pos)*4+20*(np-a[i])+nt<=time;np++) ;//电梯尽可能向上走，只要当前的i可以满足np～a[i]之间的都能到达。

np--;
nt+=(np-pos)*4;

pos=np;
}
}
return 1;
}

int main()
{
while(cin>>n&&n)
{
for(int i=0;i<n;i++)
{
cin>>a[i];
}
int st=(a[n-1]-1)*4-1;//修正误差
int et=(a[n-1]-1)*20;
int mt;
while(et-st>1)
{
mt=(st+et)/2;

if(vail(mt))
{
et=mt;
}
else
st=mt;
}

cout<<et<<endl;
}


return 0;
}
