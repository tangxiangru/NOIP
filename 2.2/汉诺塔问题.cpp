#include<iostream>
using namespace std;
char a,b,c;int n;
void hanoi(int n,char a,char b,char c)//（注意括号里是总目标）
{
if(n==0) return;//没有盘就返回零
hanoi(n-1,a,c,b);//将n-1个盘从a移动到c，以b为过度柱
cout<<a<<"->"<<n<<"->"<<b<<endl;//将第n个从a移到b
hanoi(n-1,c,b,a);//将之前的n-1个从c移动到b，以a为过度柱
}
int main()
{
cin>>n>>a>>b>>c;
hanoi(n,a,b,c);//将n个圆盘从a移动到b，以c为过度柱（总目标）
return 0;
}
