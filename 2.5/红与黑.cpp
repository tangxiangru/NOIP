#include<cstdio>
#include<iostream>
using namespace std;
int ud[5]={0,1,-1,0,0},lr[5]={0,0,0,1,-1},ans,h,l,tmp;
char a[25][25];
 
 
void zjf(int x,int y){
	if(x<1||y<1||x>h||y>l||a[x][y]=='#')
		return;
	a[x][y]='#';
	for(int i=1;i<=4;i++)
		zjf(x+ud[i],y+lr[i]);
	tmp++;
	if(tmp>ans)
		ans=tmp;
}
 
 
int main()
{
	while(1){
		tmp=ans=0;
		int p,q;
		cin>>l>>h;
		if(h==0&&l==0)
			return 0;
		for(int i=1;i<=h;i++)
			for(int j=1;j<=l;j++){
				cin>>a[i][j];
				if(a[i][j]=='@'){p=i;q=j;}
			}
		zjf(p,q);
		cout<<ans<<endl;
	}
}
