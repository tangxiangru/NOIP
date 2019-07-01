#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getValue(char ch) //将字符c转换为对应的数字
{
if(ch >= '0' && ch <= '9') return ch - '0';
else if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
}
//将from进制下的字符串转换为to进制下的整数
string change(string s, int from, int to)
{
string res = "";
int len = s.size();
int sum = 1, r, g, t;
while(sum != 0) //商数所在位上的每一位都为0
{
r = sum = 0;
for(int i = 0; i < len; i++)
{
int t = getValue(s[i]);
sum += t; //统计商数各位位置上的和
g = from*r+t; //r表示上一步运算产生的余数
s[i] = idx[g/to]; //存储新进制下的商
r = g % to; //除n取余
}

if(sum > 0)
res = idx.substr(r,1) + res; //先得到的余数放在低位
}
if(res == "") //result为空串表示转换得到的结果为0
res = "0";
return res;
}

int main()
{
int m, p, q;
string n, s;

cin >> m;
while(m--)
{
//字符串截取
string s, n;
cin >> s;
int len = s.size();
int pos1 = s.find(',');
p = atoi(s.substr(0,pos1).c_str()); //起始地址和截取长度
int pos2 = s.rfind(',');
q = atoi(s.substr(pos2+1,len-pos2+1).c_str());
n = s.substr(pos1+1,pos2-pos1-1);

if(p == q)
cout << n << endl;
else
{
cout << change(n, p, q) << endl;
}
}
return 0;
}
