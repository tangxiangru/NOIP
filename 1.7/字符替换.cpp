#include<string>
#include<iostream>

using namespace std;

string word;

char OPEN_,NOW_CSN_;

char char_(char char__)
{
    if(char__==OPEN_) return NOW_CSN_;
    else return char__;
}

int main()
{
    cin>>word>>OPEN_>>NOW_CSN_;
    for(int i=0;i<word.length();i++) word[i]=char_(word[i]);
    cout<<word<<endl;
    return 0;
}
