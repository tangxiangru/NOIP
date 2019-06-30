#include<cstdio>

using namespace std;

char word[101];

inline char char_(char char__)
{
    if(char__=='Z') return 'A';
    else if(char__=='z') return 'a';
    else if(char__<'Z'&&char__>='A') return char__+1;
    else if(char__<'z'&&char__>='a') return char__+1;
    else return char__;
}
int main()
{
    gets(word);
    for(int i=0;i<=100;i++) word[i]=char_(word[i]);
    //output();
    puts(word);
    return 0;
}
