#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int t;

string word_1,word_2;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>word_1>>word_2;
        if(word_1[0]=='R')
        {
            if(word_2[0]=='R') printf("Tie\n");
            if(word_2[0]=='P') printf("Player2\n");
            if(word_2[0]=='S') printf("Player1\n");
        }
        if(word_1[0]=='S')
        {
            if(word_2[0]=='S') printf("Tie\n");
            if(word_2[0]=='R') printf("Player2\n");
            if(word_2[0]=='P') printf("Player1\n");
        }
        if(word_1[0]=='P')
        {
            if(word_2[0]=='P') printf("Tie\n");
            if(word_2[0]=='S') printf("Player2\n");
            if(word_2[0]=='R') printf("Player1\n");
        }
    }
    return 0;
}
