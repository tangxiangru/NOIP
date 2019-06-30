#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int ans=0;

char word[300];

int main()
{
    gets(word);
    for(int i=0;i<300;i++) if(word[i]>='0'&&word[i]<='9') ans++;
    printf("%d\n",ans);
    return 0;
}
