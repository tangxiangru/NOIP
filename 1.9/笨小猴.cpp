#include <iostream>
#include <math.h>
using namespace std;
bool isPrime(int n)
{
	if(n<=1)
		return false;
	else
	{
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
				return false;
		}
		return true;
	}
}
 
int main()
{
	int count[26]={0};//务必初始化为全0
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		count[str[i]-'a']++;
	}
	int maxC=0, minC=100;
	for (int i = 0; i < 26; ++i)
	{
		if(count[i]>maxC) maxC=count[i];
		if(count[i]>0&&count[i]<minC) minC=count[i];
	}
	int d = maxC-minC;
	if(isPrime(d))
	{
		cout<<"Lucky Word"<<endl;
		cout<<d;
	}
	else
	{
		cout<<"No Answer"<<endl;
		cout<<0;
	}
	return 0;
}

