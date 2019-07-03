#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[201][201];
int b[40401],c[40401];
int e[40401];
int x[5]={0,1,0,-1,0};
int y[5]={0,0,1,0,-1};//<span style="font-family: Arial, Helvetica, sans-serif;">方向坐标移动，方便后面的for循环</span>
int tot=0;
void print(int d)
{
	tot++;
	if(e[d]!=0)
		print(e[d]);
	return;
}
int main()
{
	int R,C;
	while(1){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(e,0,sizeof(e));//清零
		int head=0,tail=1,xz=0,yz=0,f=0;
		tot=0;
		scanf("%d%d",&R,&C);
		if(!R&&!C)
			return 0;
		for(int i=1;i<=R;i++)//广搜
			for(int r=1;r<=C;r++){
				cin>>a[i][r];
				if(a[i][r]=='@'){
					a[i][r]='#';
					b[tail]=i;
					c[tail]=r;
					continue;
				}
				if(a[i][r]=='*'){
					xz=i;
					yz=r;
					continue;
				}
			}
		do{
			head++;
			for(int i=1;i<=4;i++){
				if(b[head]+x[i]>=1&&b[head]+x[i]<=R&&c[head]+y[i]>=1&&c[head]+y[i]<=C&&a[b[head]+x[i]][c[head]+y[i]]!='#'){
					tail++;
				e[tail]=head;
				b[tail]=b[head]+x[i];
				c[tail]=c[head]+y[i];
				if(b[tail]==xz&&c[tail]==yz){
					f=1;
					print(tail);
					printf("%d\n",tot-1);
					break;
				}
				a[b[tail]][c[tail]]='#';
				}
			}
			if(f==1)
				break;
			else
				continue;
		}while(head!=tail);
		if(f!=1)
			printf("-1\n");
		else
			continue;
	}
}
