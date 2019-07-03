#include<bits/stdc++.h>
using namespace std;
int z,q,s,l;
struct st
{
int tz;
string name;
};
st a[100];
bool cmp(const st & x,const st &y)
{
return x.tz<y.tz;
}
int main()
{
for(z=10;z<=50;z+=10)
for(q=10;q<=50;q+=10)
for(s=10;s<=50;s+=10)
for(l=10;l<=50;l+=10)
{
if((z+q==s+l) && (z+l>s+q) && (z+s<q))
{
a[1].name='z';
a[1].tz=z;
a[2].name='q';
a[2].tz=q;
a[3].name='s';
a[3].tz=s;
a[4].name='l';
a[4].tz=l;
}
}
sort(a+1,a+1+4,cmp);
for(int i=1;i<=4;i++)
{
cout<<a[i].name<<" "<<a[i].tz<<endl;
}
return 0;
}
