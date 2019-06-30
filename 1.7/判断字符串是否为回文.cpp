#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	char  a[102],b[102];
	cin >> a;
	int len = strlen(a);
	for( int i = 0; i < len ; i++ )
	{
		b[len - i - 1] = a[i];
	}
	int flag = 0;
	for(int i = 0 ; i < len ; i++)
	{
		if(a[i] != b[i])
		{
			flag = 1;
			break;
		}
		
	}
	if(!flag)
	cout << "yes";
	else
	cout << "no";
}
