#include <iostream>

using namespace std;

int f(int n)
{
if(n == 1) return 1;
if(n == 2) return 2;
if(n != 1 && n != 2) return f(n-1) + f(n-2);
}
int main()
{
int n;
while(cin >>n)
cout << f(n) <<endl;
return 0;
}
