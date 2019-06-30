#include<iostream>
using namespace std;
int main ()
{
	string s1, s2;
	string s3, s4;
	getline(cin,s1);
	getline(cin,s2);
	int s1len = s1.length();
	int s2len = s2.length();
	for (int i = 0; i < s1len; i++)
	{
		if(s1[i] <= 'Z' && s1[i] >= 'A')
			s1[i] += 32;
		if(s1[i] != ' ')
			s3 += s1[i]; //把s1赋值到s3上
	} 
	for (int i = 0; i < s2len; i++)
	{
		if(s2[i] <= 'Z' && s2[i] >= 'A')
			s2[i] += 32;
		if(s2[i] != ' ')
			s4 += s2[i];
	} 
	if(s3 == s4)
	cout << "YES" << endl;
	else
	cout << "NO" << endl;
	return 0;
}
