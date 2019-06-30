#include<cstdio>

using namespace std;

int now=0;

char word[105],ans[105];

int main()
{
    word[now]=getchar();
    while(word[now]!='\n') word[++now]=getchar();
    for(int i=0;i<now-1;i++) ans[i]=word[i]+word[i+1];
    ans[now-1]=word[now-1]+word[0];
    for(int i=0;i<now;i++) putchar(ans[i]);
    putchar('\n');
    return 0;
}
