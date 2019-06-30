#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void turn(char &x);
int main()
{
	char key[1000],secret[1000];
	int len1,len2;
	int i,j;
 
	gets(key);//输入密钥
	gets(secret);//输入密文
	len1=strlen(key);//求密钥长度
	len2=strlen(secret);//求密文长度
	
	for(i=0;i<len1;i++)//将密钥转换为大写字母
		turn(key[i]);
 
	for(i=0,j=0;i<len2;i++)//从头开始解密
	{
		if(secret[i]<='Z')//大写的情况
		{
			secret[i]=secret[i]-(key[j]-'A');//按规则解密
			j++;
			if(secret[i]<'A')//若明文小于A
				secret[i]='Z'-('A'-secret[i])+1;//从字母表倒序转换
		}
		else//小写的情况
		{
			secret[i]=secret[i]-(key[j]-'A');//按规则解密
			j++;
			if(secret[i]<'a')//若明文小于a
				secret[i]='z'-('a'-secret[i])+1;//从字母表倒序转换
		}
		if(j>len1-1)//若明文长度大于密钥长度，重复使用密钥
			j=0;
	}
	cout<<secret<<endl;
    return 0;
}
void turn(char &x)
{
	if((x>='a')&&(x<='z'))
		x-=32;
}
