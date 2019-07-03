#include <iostream>
using namespace std;
bool pd(int x,int y) {
int xc=x,yc=y;
int ansx=0,ansy=0;
while (xc>1){
if (xc%2==1)
ansx++;
xc/=2;
}
while (yc>1){
if (yc%2==1)
ansy++;
yc/=2;
}
if (ansx==ansy)
return true;
return false;
}
int main() {
int i=1,j;
while (1) {
cin>>i;
if (i==0)
return 0;
j=i+1;
while (pd(i,j)==false) {
j++;
}
cout<<j<<endl;
}
return 0;
}
