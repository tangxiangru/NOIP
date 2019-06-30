#include<cstdio>

using namespace std;

double ans_,ans=0;

char word_1[550],word_2[550],ch;

int main()
{
    scanf("%lf",&ans_);
    ch=getchar();
    gets(word_1);
    gets(word_2);
    int now=0;
    while(word_1[now]>='A'&&word_1[now]<='Z')
    {
        if(word_1[now]==word_2[now]) ans+=1;
        now++;
    }
    ans=ans/(double)now;
    if(ans>=ans_-0.001) printf("yes\n");
    else printf("no\n");
    return 0;
}
