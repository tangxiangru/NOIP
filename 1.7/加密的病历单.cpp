#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int len;

string word;

void trun()
{
    int l=0,r=len-1;
    while(r>l)
    {
        swap(word[l],word[r]);
        r--,l++;
    }
}

inline char char_(char char__)
{
    if(char__>='A'&&char__<='Z')
    {
        char__+=3;
        if(char__>'Z') char__-=26;
        char__+=32;
    }
    else if(char__>='a'&&char__<='z')
    {
        char__+=3;
        if(char__>'z') char__-=26;
        char__-=32;
    }
    return char__;
}

int main()
{
    cin>>word;
    len=word.length();
    trun();
    for(int i=0;i<len;i++) word[i]=char_(word[i]);
    cout<<word<<endl;
    return 0;
}
