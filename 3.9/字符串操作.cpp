#include<cctype>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define N 25
#define LEN 1100
using namespace std;
char str[N][LEN],buf[1000][LEN],*st[LEN];
int top,tot,n;
void Asshole()
{
while(1)
puts("fuck");
}
char *getbuf()
{
if(top)
return st[top--];
return buf[tot++];
}
void delbuf(char *s)
{
st[++top]=s;
}
int getop(char *s)
{
int len=strlen(s);
if(strncmp(s,"copy",4)==0&&len==4) return 1;
if(strncmp(s,"add",3)==0&&len==3) return 2;
if(strncmp(s,"find",4)==0&&len==4) return 3;
if(strncmp(s,"rfind",5)==0&&len==5) return 4;
if(strncmp(s,"insert",6)==0&&len==6) return 5;
if(strncmp(s,"reset",5)==0&&len==5) return 6;
if(strncmp(s,"print",5)==0&&len==5) return 7;
if(strncmp(s,"printall",8)==0&&len==8) return 8;
if(strncmp(s,"over",4)==0&&len==4) return 9;
return 0;
}
char *copy(int l,int f,int x)
{
char *ret=getbuf();
memcpy(ret,str[x]+f,sizeof(char)*l);
ret[l]='\0';
return ret;
}
char *add(char *b,char *a)
{
int lena=strlen(a),lenb=strlen(b);
int reta,retb,i;
char *ret=getbuf();
for(i=0,reta=0;i<lena;i++)
{
if(!isdigit(a[i]))
{
reta=-1;
break;
}
reta=reta*10+a[i]-'0';
if(reta>99999)
{
reta=-1;
break;
}
}
for(i=0,retb=0;i<lenb;i++)
{
if(!isdigit(b[i]))
{
retb=-1;
break;
}
retb=retb*10+b[i]-'0';
if(retb>99999)
{
retb=-1;
break;
}
}
if(reta!=-1&&retb!=-1)
{
sprintf(ret,"%d",reta+retb);
}
else
{
memcpy(ret,a,sizeof(char)*(lena));
memcpy(ret+lena,b,sizeof(char)*(lenb+1));
}
delbuf(a),delbuf(b);
return ret;
}
int find(int x,char *s)
{
int lens=strlen(s),lenx=strlen(str[x]);
for(int i=0;i<lenx;i++)
{
if(strncmp(s,str[x]+i,lens)==0)
{
delbuf(s);
return i;
}
}
delbuf(s);
return lenx;
}
int rfind(int x,char *s)
{
int lens=strlen(s),lenx=strlen(str[x]);
for(int i=lenx-1;i>=0;i--)
{
if(strncmp(s,str[x]+i,lens)==0)
{
delbuf(s);
return i;
}
}
delbuf(s);
return lenx;
}
char *STR();
int NUM()
{
int ret;
if(scanf("%d",&ret)==0)
{
char *op=getbuf();
scanf("%s",op);
int t=getop(op);
delbuf(op);
switch(t)
{
case 3:
return find(NUM(),STR());
case 4:
return rfind(NUM(),STR());
default:
Asshole();
}
}
else
return ret;
}
char *STR()
{
char *op=getbuf();
scanf("%s",op);
int t=getop(op);
switch(t)
{
case 0:
return op;
case 1:
delbuf(op);
return copy(NUM(),NUM(),NUM());
case 2:
delbuf(op);
return add(STR(),STR());
default:
Asshole();
}
}
void insert(int f,int x,char *s)
{
char *temp=getbuf();
int len1=strlen(str[x]),len2=strlen(s);
memcpy(temp,str[x]+f,sizeof(char)*(len1-f));
memcpy(str[x]+f,s,sizeof(char)*len2);
memcpy(str[x]+f+len2,temp,sizeof(char)*(len1-f));
delbuf(temp);
delbuf(s);
str[x][len1+len2]='\0';
}
void reset(int x,char *s)
{
memcpy(str[x],s,sizeof(char)*(strlen(s)+1));
delbuf(s);
}
void print(int x)
{
printf("%s\n",str[x]);
}
void printall()
{
for(int i=1;i<=n;i++)
{
printf("%s\n",str[i]);
}
}
int main()
{
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
scanf("%s",str[i]);
}
int t;
char *op=getbuf();
do
{
scanf("%s",op);
t=getop(op);
switch(t)
{
case 1:
copy(NUM(),NUM(),NUM());
break;
case 2:
add(STR(),STR());
break;
case 3:
find(NUM(),STR());
break;
case 4:
rfind(NUM(),STR());
break;
case 5:
insert(NUM(),NUM(),STR());
break;
case 6:
reset(NUM(),STR());
break;
case 7:
print(NUM());
break;
case 8:
printall();
break;
}
}while(t!=9);
delbuf(op);
return 0;
}
