//后缀表达式用栈来计算
//内存用优先队列实现
//用字符串和atof()来判断运算符
#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
struct cmp{
bool operator () (long double a,long double b)
{
return a>b;
}
};
priority_queue<long double,deque<long double>,cmp> mem;
stack<long double> st;
int n;
int main()
{
// freopen("input.txt","r",stdin);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n;
long double t;
for(int i=0;i<n;i++)
{
cin>>t;
mem.push(t);
}
string obj;
while(cin>>obj)
{
if(obj=="=")
{
cout<<scientific<<setprecision(6)<<st.top()<<endl;
mem.pop();
mem.push(st.top());
}
else if(obj!="+" && obj!="-" && obj!="*" && obj!="/" && obj!="=" && obj!="^")
{
st.push(atof(obj.c_str()));
}
else if(obj=="+")
{
long double n1=st.top();
st.pop();
long double n2=st.top();
st.pop();
st.push(n2+n1);
}
else if(obj=="-")
{
long double n1=st.top();
st.pop();
long double n2=st.top();
st.pop();
st.push(n2-n1);
}
else if(obj=="*")
{
long double n1=st.top();
st.pop();
long double n2=st.top();
st.pop();
st.push(n2*n1);
}
else if(obj=="/")
{
long double n1=st.top();
st.pop();
long double n2=st.top();
st.pop();
st.push(n2/n1);
}
else if(obj=="^")
{
long double n1=st.top();
st.pop();
long double n2=st.top();
st.pop();
st.push(pow(n2,n1));
}
}
cout<<endl;
short sum=0;
while(!mem.empty())
{
cout<<scientific<<setprecision(6)<<mem.top()<<' ';
mem.pop();
++sum;
if(sum==10)
{
cout<<endl;
sum=0;
}
}
}
