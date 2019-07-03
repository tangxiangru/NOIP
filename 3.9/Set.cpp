//set
#include<iostream>
#include<cstring>
#include<string>
#include<set>
using namespace std;
multiset<int> deal;
const int MAXN=0x7ffffff;
bool inputflag[MAXN];
void operate(string request,int number)
{
if(request=="add")
{
deal.insert(number);
inputflag[number]=true;
cout<<deal.count(number)<<endl;
}
if(request=="del")
{
cout<<deal.count(number)<<endl;
deal.erase(number);
}
if(request=="ask")
{
cout<<inputflag[number]<<' ';
cout<<deal.count(number)<<endl;
}
}
int main()
{
ios::sync_with_stdio(false);
memset(inputflag,false,sizeof(inputflag));
int n;
cin>>n;
while(n--)
{
string r;
int n;
cin>>r>>n;
operate(r,n);
}
return 0;
}
