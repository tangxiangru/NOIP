
#include "iostream"
using namespace std;
int main()
{
    int N;
    cin>>N;
    string str[101];
    int gre[101];
    for(int i=0;i<N;i++)
    {
        cin>>gre[i]>>str[i];
    }
    int max=0,maxpos=0;
    for(int i=0;i<N;i++)
    {
        if(max<gre[i]){
            max=gre[i];
            maxpos=i;
        }
    }
    cout<<str[maxpos];
    return 0;
}

