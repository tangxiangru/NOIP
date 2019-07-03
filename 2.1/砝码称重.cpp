#include <iostream>
using namespace std;
int x[7],a[7],h[1001],s;
int main(int argc, char *argv[]) {
for(int i=1;i<=6;i++)cin>>a[i];
for(x[1]=0;x[1]<=a[1];x[1]++)
for(x[2]=0;x[2]<=a[2];x[2]++)
for(x[3]=0;x[3]<=a[3];x[3]++)
for(x[4]=0;x[4]<=a[4];x[4]++)
for(x[5]=0;x[5]<=a[5];x[5]++)
for(x[6]=0;x[6]<=a[6];x[6]++)
h[1*x[1]+2*x[2]+3*x[3]+5*x[4]+10*x[5]+20*x[6]]=1;
for(int i=1;i<=1000;i++)s=s+h[i];
cout<<"Total="<<s<<endl;
return 0;
}


