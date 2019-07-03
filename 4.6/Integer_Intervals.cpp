
/*Greed*/

#include<iostream>
#include<algorithm>
using namespace std;

typedef class
{
public:
int s,e;
}interval; //间隔（区间）

int cmp(const void* a,const void* b)
{
interval* x=(interval*)a;
interval* y=(interval*)b;
return (x->e) - (y->e); //对区间按末端点排序
}

int main(void)
{
int n; //区间数
while(cin>>n)
{
interval* inter=new interval[n];

for(int i=0;i<n;i++)
cin>>inter[i].s>>inter[i].e;

qsort(inter,n,sizeof(interval),cmp); //对区间按末端点排序

int Selem=inter[0].e-1 , Eelem=inter[0].e; //当前区间所取的两个元素，初始化为第0个区间最后两个元素
int sum=2; //至少取sum个元素才能保证每个区间至少含有其中的2个元素
for(int k=1;k<n;k++)
if(inter[k].s<=Selem) //前一个区间所取的两个元素都在当前区间内
continue; //则当前区间无需取任何元素
else if(inter[k].s<=Eelem) //前一个区间所取的只有一个元素在当前区间内
{
Selem=Eelem;
Eelem=inter[k].e; //按序更新当前区间所取的两个元素：Selem与Eelem
sum++; //Eelem是新取的一个元素
}
else //前一个区间所取的没有一个元素在当前区间内
{
Selem=inter[k].e-1;
Eelem=inter[k].e; //按序更新当前区间所取的两个元素：Selem与Eelem
sum+=2; //Selem与Eelem是新取的两个元素
}
cout<<sum<<endl;

delete inter;
}
return 0;
}
