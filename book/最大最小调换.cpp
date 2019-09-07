# include <stdio.h>
int main()
{
    int i,t,maxi,mini,a[10];
    maxi=mini=0;            
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);        
    if(a[i]>a[maxi])
        maxi=i;    
    else if(a[i]<a[mini])
        mini=i;
    }
      t=a[maxi];        
      a[maxi]=a[mini];
      a[mini]=t;
      printf("最大数、最小数交换位置后：\n");   
      for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
