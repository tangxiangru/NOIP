#include<iostream>
using namespace std;
 
void bi(int, int, bool);
int main()
{
	int n;
	while (cin >> n)
	{
		if (n >= 0)
			bi(n, 32, 1);
		else
			bi(~n, 32, 0);
		cout << endl;
	}
	return 0;
}
 
void bi(int n, int m, bool b)
{
	if (m == 0)
		return;
 
	if (b)
	{
		bi(n / 2, --m, 1);
		cout << n % 2;
	}
	else
	{
		bi(n / 2, --m, 0);
		cout << (n % 2 + 1)%2 ;
	}
}
