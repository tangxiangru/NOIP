#include<cstdio>
char str[1004][25];
int n;
struct tire
{
int de;
struct tire *chil[26];
}*t=new struct tire;
void ins(int idx)
{
int i=0;
struct tire *p=t;
while(str[idx][i]!='\0')
{
if(p->chil[str[idx][i]-'a']==NULL)
{
p->chil[str[idx][i]-'a']=new struct tire;
p->chil[str[idx][i]-'a']->de=0;
for(int j=0;j<26;j++)p->chil[str[idx][i]-'a']->chil[j]=NULL;
}
(p->chil[str[idx][i]-'a']->de)++;
p=p->chil[str[idx][i++]-'a'];
}
}
void search(int idx)
{
printf("%s ",str[idx]);
int i=0;
struct tire *p=t;
while(str[idx][i]!='\0')
{
printf("%c",str[idx][i]);
if(p->chil[str[idx][i]-'a']->de==1)break;
p=p->chil[str[idx][i++]-'a'];
}
printf("\n");
}
int main()
{
for(int i=0;i<26;i++)t->chil[i]=NULL;
while(scanf("%s",str[++n])!=EOF)ins(n);
for(int i=1;i<=n;i++)search(i);
return 0;
}
