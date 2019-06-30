#include "iostream"
#include "math.h"
#include "iomanip"
using namespace std;
int main()
{
    double h;
    cin>>h;
    double h10;
    double hsum=0;
    for(int i=0;i<10;i++)
    {
        if(i!=9){
            hsum+=h;
            h=h/2;
            hsum+=h;}
        else{
            hsum+=h;
            h=h/2;
            h10=h;
        }
    }
    cout<<hsum<<endl<<h10<<endl;
    return 0;
}
