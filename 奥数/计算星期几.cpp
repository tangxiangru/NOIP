#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long zkb( long long a, long long b, int p ) {
long long ans = 1;
while( b ) {
if ( b & 1 )
ans = ans * a % p;
a = a * a % p;
b >>= 1;
}
return ans;
}
long long a,b,c;
int main(){
scanf("%d%d",&a,&b);
c=zkb(a,b,7);
switch (c){
case 1:printf("Monday");break;
case 2:printf("Tuesday");break;
case 3:printf("Wendesday");break;
case 4:printf("Thursday");break;
case 5:printf("Friday");break;
case 6:printf("Saturday");break;
case 0:printf("Sunday");break;
}
return 0;
}
