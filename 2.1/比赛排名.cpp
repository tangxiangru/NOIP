#include<stdio.h>
int main() {
int i,o;
int a[5]={0};
for(a[0]=1; a[0]<=5; a[0]++) {
for(a[1]=1; a[1]<=5; a[1]++) {
if(a[1]==a[0])continue;
for(a[2]=1; a[2]<=5; a[2]++) {
if(a[2]==a[1]||a[2]==a[0])continue;
for(a[3]=1; a[3]<=5; a[3]++) {
if(a[3]==a[2]||a[3]==a[1]||a[3]==a[0])continue;
for(a[4]=1; a[4]<=5; a[4]++) {
if(a[4]==a[2]||a[4]==a[1]||a[4]==a[0]||a[4]==a[3]||a[4]==2||a[4]==3)continue;
o=0;
if((a[4]==1)+(a[1]==2)+(a[0]==5)+(a[2]!=1)+(a[3]==1)==2)
for(i=0;i<=4;i++)
{
if(a[i]==1||a[i]==2)
switch(i)
{
case 0:if(a[4]==1)o++;break;
case 1:if(a[1]==2)o++;break;
case 2:if(a[0]==5)o++;break;
case 3:if(a[2]!=1)o++;break;
case 4:if(a[3]==1)o++;break;
}
if(o==2){printf("%d\n%d\n%d\n%d\n%d\n",a[0],a[1],a[2],a[3],a[4],a[5]);return 0;}
}
}
}
}
}
}
return 0;

}
