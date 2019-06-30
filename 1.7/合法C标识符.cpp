#include<cstdio>
#include<cstring>
char a[310];
int main(){
	scanf("%s",a+1);
	int n=strlen(a+1);
	if(a[1]>='0'&& a[1]<='9'){
	
		printf("no");
		return 0;
	}	
	for (int i =0;i<=n;i++){
		if((a[i]<'0' || a[i]>'9') && (a[i]<'A' || a[i]>'Z') && (a[i]<'a'|| a[i]>'z')&&a[i]!='_'){
			printf("no");
			return 0;
		}
		
		
	}
	printf("yes");
	return 0;
}
