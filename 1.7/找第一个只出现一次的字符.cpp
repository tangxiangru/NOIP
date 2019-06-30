#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int ans=0,num[200],has=0;

char word[100005],zmu[200];

bool if_did[200];

int main()
{
    gets(word);
    int now=0;
    while(word[now]<='z'&&word[now]>='a')
    {
        if(!if_did[word[now]])
        {
            if_did[word[now]]=true;
            zmu[++has]=word[now];
        }
        num[word[now]]++;
        now++;
    }
    bool if_zheng=true;
    for(int i=1;i<=has;i++)
    {
        if(num[zmu[i]]!=1) continue;
        if_zheng=false;
        printf("%c\n",zmu[i]);
        break;
    }
    if(if_zheng) printf("no\n");
    return 0;
}
