#include<cstdio>
#include<cstring>
char a[310];
int main(){
	gets(a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]>='A' && a[i]<='E'){
			a[i]+=21;	
		}
		else if(a[i]>='F' && a[i]<='Z'){
			a[i]-=5;
			
		}		
	}
	printf("%s",a+1);
	return 0;
}
