#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[200];
int s[100],d;
int main()
{
for(int i=0;i<4;i++)
{

cin.getline(a,90);
int l=strlen(a);
for(int i=0;i<l;i++)
++s[a[i]];}
for(int i='A';i<='Z';i++)
d=max(d,(int)s[i]);
for(int i=d;i>=1;i--)
{
for(int j=0;j<26;j++)
{

s[j+'A']>=i?printf("*"):printf(" ");
printf(" ");}
printf("\n");
}
printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
}
