#include<stdio.h>
#include<string.h>
using namespace std;
int a[10],j,k,sum=0;
int main(){
for(int i=123;i<=329;i++){
memset(a,0,10*sizeof(a[0]));
a[i/100]=1;
a[i/10%10]=1;
a[i%10]=1;
j=i*2;
a[j/100]=1;
a[j/10%10]=1;
a[j%10]=1;
k=i*3;
a[k/100]=1;
a[k/10%10]=1;
a[k%10]=1;
for(int q=1;q<10;q++){
sum+=a[q];
}
if(sum==9){printf("%d %d %d\n",i,j,k);}
sum=0;
}
return 0;}
