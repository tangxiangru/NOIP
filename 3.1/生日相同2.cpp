#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct ill{
char name[21];
};
struct node{
int num;
ill ren[185];
}day[16][35];
bool fuu(ill x,ill y)
{
if(strlen(x.name)<strlen(y.name))
return 1;
if(strlen(x.name)==strlen(y.name)&&strcmp(x.name,y.name)<0)
return 1;
return 0;
}
int main()
{
int n,m,d,i,j,k;
bool p=0;
char a[21];
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%s%d%d",a,&m,&d);
strcpy(day[m][d].ren[day[m][d].num].name,a);
day[m][d].num++;
}
for(i=1;i<=12;i++)
for(j=1;j<=31;j++)
if(day[i][j].num)
sort(day[i][j].ren,day[i][j].ren+day[i][j].num,fuu);
for(i=1;i<=12;i++)
for(j=1;j<=31;j++)
if(day[i][j].num>1)
{
p=1;
printf("%d %d",i,j);
for(k=0;k<day[i][j].num;k++)
printf(" %s",day[i][j].ren[k].name);
printf("\n");
}
if(!p)
printf("None");
}
