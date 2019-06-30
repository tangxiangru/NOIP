#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    string str;
    getline(cin,str);
    int pos;
    for(int i=0;i<str.length();i++)
    {
        if(str.at(i)=='+'||str.at(i)=='-'||str.at(i)=='*'||str.at(i)=='/'||str.at(i)=='%')
            pos=i;
    }
    //cout<<pos;
    string substr1,substr2;
    substr1=str.substr(0,pos);
    substr2=str.substr(pos+1,str.length()-pos+1);
    int a=atoi(substr1.c_str());//int atoi(const char *nptr);
    int b=atoi(substr2.c_str());
    //cout<<substr1<<" "<<substr2<<endl;
    switch(str.at(pos))
    {
        case '+':cout<<a+b;break;
        case '-':cout<<a-b;break;
        case '*':cout<<a*b;break;
        case '/':cout<<a/b;break;
        case '%':cout<<a%b;break;
        default:cout<<"wrong input";              
    }        
    return 0;
}
