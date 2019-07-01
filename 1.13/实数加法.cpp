//结尾有多余“0”的问题就是其中一个数据点的出题点。
//剩下的注意加法对应问题，小数点是重要分界。
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
string sa, sb;
cin >> sa >> sb;

int lena = sa.size(), lenb = sb.size();
int pa = sa.find("."), pb = sb.find(".");
string sa1, sa2, sb1, sb2;
sa1 = sa.substr(0,pa), sa2 = sa.substr(pa+1,lena-pa-1); //a串整数部分 小数部分
sb1 = sb.substr(0,pb), sb2 = sb.substr(pb+1,lenb-pb-1); //b串整数部分 小数部分

//小数部分计算，小数部分进位放在c2[0]中
int a2[101], b2[101], c2[101];
memset(a2,0,sizeof(a2));
memset(b2,0,sizeof(b2));
memset(c2,0,sizeof(c2));
int lensa2 = sa2.size(), lensb2 = sb2.size();
for(int i = 0; i < lensa2; i++)
a2[i+1] = sa2[i] - '0';
for(int i = 0; i < lensb2; i++)
b2[i+1] = sb2[i] - '0';
int lenc2 = max(lensa2, lensb2);
for(int i = lenc2; i >= 1; i--)
c2[i] = a2[i] + b2[i];
for(int i = lenc2; i >= 1; i--)
{
if(c2[i] >= 10)
{
c2[i-1]++;
c2[i] -= 10;
}
}


//整数部分计算
int a1[101], b1[101], c1[101];
memset(a1,0,sizeof(a1));
memset(b1,0,sizeof(b1));
memset(c1,0,sizeof(c1));
int lensa1 = sa1.size(), lensb1 = sb1.size();
for(int i = 0; i < lensa1; i++)
a1[lensa1-i] = sa1[i] - '0';
for(int i = 0; i < lensb1; i++)
b1[lensb1-i] = sb1[i] - '0';
int lenc1 = max(lensa1, lensb1);

for(int i = 1; i <= lenc1; i++)
c1[i] = a1[i] + b1[i];
c1[1] += c2[0]; //整数最低位要加上小数部分的进位
for(int i = 1; i <= lenc1; i++)
{
if(c1[i] >= 10)
{
c1[i+1]++;
c1[i] -= 10;
}
}

while(c1[lenc1+1] > 0)
lenc1++;

for(int i = lenc1; i >= 1; i--)
cout << c1[i];
cout << ".";

while(c2[lenc2] == 0) lenc2--;
for(int i = 1; i <= lenc2; i++)
cout << c2[i];
cout << endl;

return 0;
}
