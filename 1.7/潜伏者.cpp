#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int len_s,len_w;

char start[150],pass_word[150],wait_work[150];

bool if_in_1[200];

map<char,bool>if_in;
map<char,char>from_to;

int main()
{
    cin>>start;
    cin>>pass_word;
    cin>>wait_work;
    len_s=strlen(start),len_w=strlen(wait_work);
    for(int i=0;i<len_s;i++)
    {
        if(!if_in[start[i]])
        {
            if(!if_in_1[pass_word[i]])
            {
                from_to[start[i]]=pass_word[i];
                if_in[start[i]]=true;
                if_in_1[pass_word[i]]=true;
            }
            else
            {
                cout<<"Failed"<<endl;
                return 0;
            }
        }
        else
        {
            if(!if_in_1[pass_word[i]])
            {
                cout<<"Failed"<<endl;
                return 0;
            }
            if(from_to[start[i]]!=pass_word[i])
            {
                cout<<"Failed"<<endl;
                return 0;
            }
        }
    }
    for(int i='A';i<='Z';i++)
    {
        if(!if_in[i])
        {
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    for(int i=0;i<len_w;i++)
    {
        if(if_in[wait_work[i]]) wait_work[i]=from_to[wait_work[i]];
        else
        {
            cout<<"Failed"<<endl;
            return 0;
        }
    }
    for(int i=0;i<len_w;i++) putchar(wait_work[i]);
    putchar('\n');
    return 0;
}
