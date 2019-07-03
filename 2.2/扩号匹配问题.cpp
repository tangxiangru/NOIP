#include <stack>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
stack <char> ans;
char b[104];
void fff(char a[],int i,int l)
{
if(i==l)
return;
if(a[i]=='(')
{
ans.push(i);
b[i]='$';
}

if(a[i]==')')
{
if(ans.size())
{
b[ans.top()]=' ';
ans.pop();
}
else b[i]='?';
}
fff(a,i+1,l);
}

int main()
{
char a[105];
while(cin>>a)
{
memset(b,' ',sizeof(b));
int l=strlen(a);
for(int i=0;i<l-1;i++)
cout<<a[i];
cout<<a[l-1]<<endl;
fff(a,0,l);
for(int i=0;i<l;i++)
cout<<b[i];
cout<<endl;
while( !ans.empty() )
ans.pop();
}
return 0;
}
