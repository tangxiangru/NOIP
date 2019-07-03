#include<bits/stdc++.h>
using namespace std;
int m[15] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
void fun(int);
int main()
{
int f;
cin >> f;
fun(f);
return 0;
}
void fun(int f)
{
for(int i = 14; i >= 0; i--)
{
if(m[i] <= f)
{
f -= m[i];
if(f == 0)
{
if(i == 1)
cout << '2' ;
else
if(i <= 2)
cout << "2(" << i << ')';
else
{
cout << "2(";
fun(i);
cout << ')';
}
break;
}
else
if(i == 1)
cout << "2+";
else
if(i <= 2)
cout << "2(" << i << ")+";
else
{
cout << "2(";
fun(i);
cout << ")+";
}
}
}
}
