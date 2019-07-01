#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int space,len;
int word[1100]={0};//单词
int dictionary[1100]={0};//存储单元中存放的意思
bool got[1100]={false};//是否已经知道意思
int num=0;

int main()
{
    scanf("%d%d",&space,&len);
    for (int i=1; i<=len; i++)
        scanf("%d",&word[i]);
    for (int i=1; i<=len; i++)
        {
            if (got[word[i]]==false)
                {
                    if (space>num)
                        {
                            dictionary[++num]=word[i];
                            got[word[i]]=true;
                        }
                    else
                        {
                            dictionary[++num]=word[i];
                            got[word[i]]=true;
                            got[dictionary[num-space]]=false;
                        }
                }
        }
    printf("%d",num);
  return 0;
}//机器翻译
