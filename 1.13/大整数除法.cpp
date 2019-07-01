#include<cstdio>
#include<string.h>
int main(){
char s[200];
int a[200]={0},b[200]={0},c[200]={0},la,lb;
gets(s);la=strlen(s);
for(int i=1;i<=la;i++)a[i]=s[i-1]-'0';
gets(s);lb=strlen(s);
for(int i=0;i<=lb;i++)b[i]=s[i]-'0';
for(int i=1;i<=la-lb+1;i++){
while(a[i-1]>=0){
for(int j=lb-1;j>=0;j--){
a[i+j]-=b[j];
if(a[i+j]<0){a[i+j]+=10;a[i+j-1]--;}
}
c[i-1]++;
}c[i-1]--;
for(int j=lb-1;j>=0;j--){
a[i+j]+=b[j];
if(a[i+j]>9){a[i+j]-=10;a[i+j-1]++;}
}
}
if(c[0]>0)printf("%d",c[0]);
for(int i=1;i<=la-lb;i++)printf("%d",c[i]);
if(la<lb)printf("0");
}
