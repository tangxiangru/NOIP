#include<iostream>
using namespace std;
struct peo{
int y,z;
};
int a,n,m,x,ans,k,i;
peo b[10002],c[10002];
int main()
{
cin>>a>>n>>m>>x;
b[1].y=1;b[1].z=0;c[1].y=1;c[1].z=0;
b[2].y=1;b[2].z=0;c[2].y=0;c[2].z=1;
for (i=3;i<n;i++){
c[i].y=c[i-1].y+c[i-2].y;
c[i].z=c[i-1].z+c[i-2].z;
b[i].y=b[i-1].y+c[i-2].y;
b[i].z=b[i-1].z+c[i-2].z;
}
k=m-a*b[n-1].y;
if (k%b[n-1].z!=0) cout<<"No answer." <<endl;
else{
k=k/b[n-1].z;
ans=a*b[x].y+k*b[x].z;
cout<<ans<<endl;
}
return 0;
}
