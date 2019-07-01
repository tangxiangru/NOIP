#include<stdio.h>
#include<string.h>
#include<algorithm>
using std::sort;

char s1[107];
char s2[107];
int cnt1[26];
int cnt2[26];

int main(){
gets(s1);int l1=strlen(s1);
gets(s2);int l2=strlen(s2);
for(int i=0;i<l1;++i)++cnt1[s1[i]-'A'];
for(int i=0;i<l2;++i)++cnt2[s2[i]-'A'];
sort(cnt1,cnt1+26);
sort(cnt2,cnt2+26);
bool b=true;
for(int i=0;i<26;++i){
if(cnt1[i]!=cnt2[i]){
b=false;
break;
}
}
puts(b?"YES":"NO");
return 0;
}
