#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[101], b[101];

bool match(string a, string b) //a原串,b生成串
{
int lena = a.size(), lenb = b.size();
for(int k = 0; k < lena; k++)
{
int i = k, j = 0;
while(a[i % lena] == b[j])
{
i++;
j++;
}
if(j == lenb) return true; //b串全部匹配
}
return false;
}

int main()
{
string s;
cin >> s;

int len = s.size();
for(int i = 0; i < len; i++)
a[len-i] = s[i] - '0';

bool flag = true;

for(int i = 1; i <= len; i++)
{
memset(b,0,sizeof(b));
for(int j = 1; j <= len; j++)
b[j] = a[j] * i;

for(int j = 1; j <= len; j++)
{
if(b[j] >= 10)
{
b[j+1] += b[j] / 10;
b[j] = b[j] % 10;
}
}

//忽略前导0
int k;
for(k = 100; k >= 1; k--)
if(b[k] != 0) break;

string t;
for(int j = k; j >= 1; j--)
t = t + (char)(b[j] + '0');

if(!match(s,t)) //有一组数据无法匹配
{
flag = false;
break;
}
}

if(flag)
cout << 1 << endl;
else
cout << 0 << endl;

return 0;
}
