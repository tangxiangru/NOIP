#include<iostream>

using namespace std;

string word;

char char_(char char__)
{
    switch(char__)
    {
        case 'A':return 'T';
        case 'T':return 'A';
        case 'C':return 'G';
        case 'G':return 'C';
    }
}

int main()
{
    cin>>word;
    for(int i=0;i<word.length();i++)
    {
        word[i]=char_(word[i]);
    }
    cout<<word<<endl;
    return 0;
}
