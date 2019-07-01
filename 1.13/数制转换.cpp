#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
long long int a,b,c=0,d=0;
char n[10001],m[10001];
scanf("%lld %s %lld",&a,n,&b);
for(int i=strlen(n)-1;i>=0;i--)
{
if(n[i]=='A'||n[i]=='a')c+=10*pow(a,d++);
else if(n[i]=='B'||n[i]=='b')c+=11*pow(a,d++);
else if(n[i]=='C'||n[i]=='c')c+=12*pow(a,d++);
else if(n[i]=='D'||n[i]=='d')c+=13*pow(a,d++);
else if(n[i]=='E'||n[i]=='e')c+=14*pow(a,d++);
else if(n[i]=='F'||n[i]=='f')c+=15*pow(a,d++);
else c+=(n[i]-'0')*pow(a,d++);
}
if(c==0)
{
printf("0\n");
return 0;
}
d=0;
while(c)
{
m[d++]=c%b;
c=c/b;
}
for(int i=d-1;i>=0;i--)
{
if(m[i]==10) printf("A");
else if(m[i]==11) printf("B");
else if(m[i]==12) printf("C");
else if(m[i]==13) printf("D");
else if(m[i]==14) printf("E");
else if(m[i]==15) printf("F");
else printf("%d",m[i]);
}
return 0;
}
