#include<cstdio>
#include<iostream>
using namespace std;
char a[105][105];
int ans,lr[9]={0,0,1,1,1,0,-1,-1,-1},ud[9]={0,1,1,0,-1,-1,-1,0,1};
int n,m;
void zjf(int i,int j){
	if(i<1||j<1||i>n||j>m)        //越界返回
		return;
	a[i][j]='.';                  //填坑
	for(int g=1;g<=8;g++)         //把周围的坑都填上，而且重复搜索
		if(a[i+lr[g]][j+ud[g]]=='W')
			zjf(i+lr[g],j+ud[g]);
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='W'){zjf(i,j);ans++;}
	cout<<ans;
}
