#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
 
int main(int argc, char *argv[])
{
    int count;
    cin>>count;
    float num,sum=0;
    for(int i=0;i<count;i++)
    {
        cin>>num;
        sum+=ceil(num/(float)70)*0.1;
    }
    cout<<sum;
    return 0;
}
