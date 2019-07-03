#include <stdio.h>
#include <cmath>
#include <algorithm>
#include<iostream>
#include<string.h>
using namespace std;
bool find(char a[],char b){
int l=strlen(a);
for(int i=0;i<l;i++)if(a[i]==b)return 1;
return 0;
}
int main( ){
int n,coin[12]={0};
char a[3][13],b[3][13],c[3][5];
scanf("%d",&n);
while(n--){
memset(coin,0,sizeof(coin));
for(int i=0;i<3;i++){
scanf("%s %s %s",&a[i],&b[i],&c[i]);
if(strcmp(c[i],"even")==0)
for(int j=0,l=strlen(a[i]);j<l;j++){
coin[a[i][j]-'A']=1;
coin[b[i][j]-'A']=1;
}
}
for(int i=0;i<12;i++){
for(int j=0;j<3&&coin[i]!=1;j++){
int f1=find(a[j],i+'A'),f2=find(b[j],i+'A');
if(strcmp(c[j],"up")==0){
if(coin[i]==0){
if(f1)coin[i]=3;
else if(f2)coin[i]=2;
else coin[i]=1;
}
if(coin[i]==2)if(f1||(f2==0))coin[i]=1;
if(coin[i]==3)if((f1==0)||f2)coin[i]=1;
}
if(strcmp(c[j],"down")==0){
if(coin[i]==0){
if(f1)coin[i]=2;
else if(f2)coin[i]=3;
else coin[i]=1;
}
if(coin[i]==2)if((f1==0)||f2)coin[i]=1;
if(coin[i]==3)if(f1||(f2==0))coin[i]=1;
}
//cout<<char(i+'A')<<" "<<j<<" "<<coin[i]<<endl;
//if(coin[i]==0)printf(" %d",j+1);
}
if(coin[i]==2||coin[i]==3){
printf("%c is the counterfeit coin and it is ",i+'A');
if(coin[i]==2)printf("light.\n");else printf("heavy.\n");
break;
}
}
}
return 0;
}
