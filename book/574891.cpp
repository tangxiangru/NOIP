#include<stdio.h>
#define N 6
int main() 
 
{  
	int a[N],i,j,k,m; 
 	printf("请输入六个数字：\n",i );
 
	for(i=0;i<6;i++)  
	 
		scanf("%d",&a[i]); 
 
 
	for(i=5;i>=0;i--)  
 
	{  
	
		k=a[5];   
	
		for(j=4 ;j>=0;j--)    
		
			a[j+1]=a[j];  
	
		a[0]=k ;   
	
		for(m=0;m<6;m++)    
		
			printf("%3d",a[m]); 
  
		printf("\n"); 
 
	} 
}
