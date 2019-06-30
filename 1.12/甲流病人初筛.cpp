#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    int count;
    cin>>count;
    string name;
    float degree;
    int flag;
    int sum=0;
    for(int i=0;i<count;i++)
    {
       cin>>name>>degree>>flag;   
       if(flag&°ree>=37.5)
       {
           cout<<name<<endl;
           sum++;
       }  
    }
    cout<<sum;
    return 0;
}
