

#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
 
using namespace std;
 
,ans=,ans_first=0x7fffffff;
 
],now[];
 
void if_ok(int now_)
{
    ||now[now_-]==||now[now_+len_start]==' '))
    {
        bool if_add=true;
        ;i<len_start;i++)
        {
            if(now[now_+i]==start[i]) continue;
            if_add=false;
            break;
        }
        if(if_add)
        {
            ans++;
            ans_first=min(ans_first,now_);
        }
    }
}
 
inline void char_(char &char__)
{
    ;
}
 
int main()
{
    gets(start);
    gets(now);
    len_start=strlen(start),len_now=strlen(now);
    ;i<len_start;i++) char_(start[i]);
    ;i<len_now;i++) char_(now[i]);
    //printf("%s\n",start);
    //printf("%s\n",now);
    ;i<=len_now-len_start;i++)
    {
        ]) if_ok(i);
    }
    ) printf("-1\n");
    else printf("%d %d\n",ans,ans_first);
    ;
}


