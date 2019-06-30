#include<iostream>
#include<cstring>
using namespace std;


int main ()
{
	int next[205];
	int s1len, s2len , s3len, s4len;
	string s1, s2, s3 ,s4;
	getline(cin,s1);
	getline(cin,s2);
	s1len = s1.length();
	s2len = s2.length();
	if(s1len < s2len)
	{
		s3 = s1;
		s4 = s2;
		s3len = s1len;
		s4len = s2len;
	}
	else
	{
		s3 = s2;
		s4 = s1;
		s3len = s2len;
		s4len = s1len;
	}
	
	int k = -1;
	int j = 0;
	next[0] = -1;
	next[1] = 0;
	while (j < s3len)
	{
		if(k == -1 || s3[j] == s3[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		k = next[k];
	}
	j = 0;
	int i = 0;
	while(i < s4len && j < s3len)
	{
		if( j == -1 || s3[j] == s4[i])
		{
			i++;
			j++;
		}
		else if(j != -1 && s3[j] != s4[i])
		j = next[j];
	}
	if(j == s3len)
	cout << s3 << " is substring of " << s4 << endl;
	else
	cout <<  "No substring" << endl;
}
