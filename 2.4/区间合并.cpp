#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data{
    int head,tail;
};
data qj[50010]={0};
int cmp(data x,data y)
{
  if (x.head<y.head)
   return 1;
  else
   if (x.head==y.head)
    if (x.tail<=y.tail)
     return 1;
    else
     return 0;
   else
    return 0;   
}

int main()
{
    int n;
    bool f=false;
    int start=0,end=0;//如果可以合并，开头和结尾 
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i++)
     { 
      scanf("%d%d",&qj[i].head,&qj[i].tail);
      end=max(end,qj[i].tail);//表示结尾的取所有区间的结尾的最大值 
     }
    sort(qj+1,qj+n+1,cmp);//按照区间的开头进行排序，从小到大，一样则结尾从小到大排序 
    start=qj[1].head;//表示开头的为最小的那个 
    int h=qj[1].head,t=qj[1].tail;//为下文判断是否可以合并做准备 
    for (i=2;i<=n;i++)
      if (qj[i].head>t)//因为有序，满足这个就不能合并 
       {f=true;break;}
      else
       t=max(t,qj[i].tail); //两个合并后，把当前最大的结尾记录，为以后对比做铺垫 
    if (!f)
     printf("%d %d",start,end);
    else
     printf("no");
 return 0;   
}
