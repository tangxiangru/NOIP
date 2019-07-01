#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct node
{
    int x,y,value;
};

int m,n,k,t;

struct node p[1000];

int mov(int now)//计算并返回从now-1那个点到第now个点需要的时间
{
    int mo;
    mo=abs(p[now-1].x-p[now].x)+abs(p[now-1].y-p[now].y);
    return mo;
}

void bubble()//冒泡排序
{
   for (int i=1;i<t;i++)
     for (int j=i+1;j<=t;j++)
       if (p[i].value<p[j].value) 
       {
           swap(p[i].x,p[j].x);
           swap(p[i].y,p[j].y);
           swap(p[i].value,p[j].value);
       }
}

int main()
{
   cin>>m>>n>>k;
   t=0;
   int i,j;
   for (i=1;i<=m;i++)  
    for (j=1;j<=n;j++)
     {
        cin>>p[++t].value;
        p[t].x=j; p[t].y=i;
        if (p[t].value==0) {t--;}
     }
   bubble();
   int now,ans;
   now=1; ans=0;
   p[0].x=p[1].x;p[0].y=0; p[0].value=0; //第1个点从路边走直线到达
   while ((k>0)&&((k-mov(now))>p[now].y))//必须有足够时间去到第now个点、采摘花生、并且确保至少能从那地方直接返回路边，才能从now-1去第now个点。
   {
       k-=mov(now);
       k--;//采摘花生也要花时间的。这就是上面((k-mov(now))>p[now].y)不用>=号的原因了
       ans+=p[now].value;
       now++;
   }
   cout<<ans;
   return 0;
}
