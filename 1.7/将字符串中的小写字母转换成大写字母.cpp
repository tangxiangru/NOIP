#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int len;

char word[150];

inline char char_(char char__)
{
    if(char__>='a'&&char__<='z') char__-=32;
    return char__;
}

int main()
{
    gets(word);
    len=strlen(word);
    for(int i=0;i<len;i++) word[i]=char_(word[i]);
    puts(word);
    cout<<endl;
    return 0;
}
