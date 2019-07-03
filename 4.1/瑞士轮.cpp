#include<bits/stdc++.h>
using namespace std;
int peo,cir,care;
struct C_w{
int grades,strong,nmm,win;
}man[200001],sss[200001];
int tyh(const C_w &x,const C_w &y)
{
if(x.grades>y.grades)return 1;
else if(x.grades==y.grades&&x.nmm<y.nmm)return 1;
else return 0;
}
void c_wen(int left,int right)
{

int zz=left,win=left,lose=left;
while(man[win].win!=1)
{
win++;
if(win>2*peo)break;
}
while(man[lose].win!=0)
{
lose++;
if(lose>2*peo)break;
}
while(win<=right&&lose<=right&&zz<=right)
{
if(man[win].grades>man[lose].grades||(man[win].grades==man[lose].grades&&man[win].nmm<man[lose].nmm))
{
sss[zz].grades=man[win].grades;
sss[zz].nmm=man[win].nmm;
sss[zz].strong=man[win].strong;
sss[zz].win=man[win].win;
zz++;
win++;
while(man[win].win!=1)
{
win++;
if(win>2*peo)break;
}
}
else
{
sss[zz].grades=man[lose].grades;
sss[zz].nmm=man[lose].nmm;
sss[zz].strong=man[lose].strong;
sss[zz].win=man[lose].win;
zz++;
lose++;
while(man[lose].win!=0)
{
lose++;
if(lose>2*peo)break;
}
}
}

while(win<=right)
{
sss[zz].grades=man[win].grades;
sss[zz].nmm=man[win].nmm;
sss[zz].strong=man[win].strong;
sss[zz].win=man[win].win;
zz++;
win++;
while(man[win].win!=1)
{
win++;
if(win>2*peo)break;
}
}

while(lose<=right)
{
sss[zz].grades=man[lose].grades;
sss[zz].nmm=man[lose].nmm;
sss[zz].strong=man[lose].strong;
sss[zz].win=man[lose].win;
zz++;
lose++;
while(man[lose].win!=0)
{
lose++;
if(lose>2*peo)break;
}
}

for(int i=left;i<=right;i++)
{
man[i].grades=sss[i].grades;
man[i].nmm=sss[i].nmm;
man[i].strong=sss[i].strong;
man[i].win=sss[i].win;
}
}
int main()
{
cin>>peo>>cir>>care;
for(int i=1;i<=2*peo;i++)
{
scanf("%d",&man[i].grades);
man[i].nmm=i;
}

for(int j=1;j<=2*peo;j++)scanf("%d",&man[j].strong);

sort(man+1,man+2*peo+1,tyh);

for(int i=1;i<=cir;i++)
{
for(int j=1;j<=2*peo;j+=2)
{
if(man[j].strong>man[j+1].strong)
{
man[j].grades++;
man[j].win=1;
man[j+1].win=0;
}
else
{
man[j+1].grades++;
man[j+1].win=1;
man[j].win=0;
}
}
// sort(man+1,man+2*peo+1,tyh);
c_wen(1,2*peo);
}
sort(man+1,man+2*peo+1,tyh);
cout<<man[care].nmm;
return 0;
}
