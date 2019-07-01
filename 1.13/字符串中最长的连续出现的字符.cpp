#include<iostream>
#include<cstring>
using namespace std;
int main()
{
char s[205],maxch;
int maxn=0,k=1;
cin>>s;
for (int i=1; i<strlen(s); i++)
if (s[i]==s[i-1])
k++;
else
{
if (k>maxn)
{
maxch=s[i-1];
maxn=k;
}
k=1;
}
if (k>maxn)
{
maxch=s[strlen(s)-1];
maxn=k;
}
cout<<maxch<<" "<<maxn;
return 0;
}
