#include<iostream>
#include<cstdio>
using namespace std;
int a[100010]={0},L[100010]={0},R[100010]={0};
long long ans=0;
#define M 1000000000;

void gb(int left,int mid,int right)
{
    int ll=mid-left+1; 
    int lr=right-mid;
     for (int i=1;i<=ll;i++)
      L[i]=a[left+i-1];//此操作方便处理 
     for (int i=1;i<=lr;i++)
      R[i]=a[mid+i];
     L[ll+1]=M;//将最后一个赋给一个极大值，可以当作一个“哨兵”非常的精妙，然而经测试似乎不加这条语句会出错 
     R[lr+1]=M;
     int l=1,r=1;
     for (int i=left; i<=right; i++)
      {
        if (L[l]<=R[r])
         {
          a[i]=L[l];
          l++;
         }
        else
         {
          a[i]=R[r];
          r++;
          ans+=ll-l+1;//求逆序对的唯一多出来的语句 
         }
      }
}

void gbsort(int left,int right)
{
  int mid=(left+right)/2;
  if (left<right)
   {
     gbsort(left,mid);//不断分治 
     gbsort(mid+1,right);
     gb(left,mid,right);
   }    
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
     scanf("%d",&a[i]);
    gbsort(1,n);
    printf("%lld",ans);
  return 0;
}
