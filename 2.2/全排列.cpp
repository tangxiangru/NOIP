#include<bits/stdc++.h>
using namespace std;
int l;
string s;
char c[7];
bool check(int dep)
{
for (int i=1;i<dep;i++)
if (c[i]==c[dep])return 0;
return 1;
}
void print(int dep)
{
for (int i=1;i<dep;i++)
cout<<c[i];
cout<<endl;
}
void work(int dep)
{
if (dep>l)
{
print(dep);
return ;
}
for (int i=0;i<l;i++)
{
c[dep]=s[i];
if (check(dep))work(dep+1);
}
}
int main()
{
cin>>s;
l=s.length();
work(1);
return 0;
}
