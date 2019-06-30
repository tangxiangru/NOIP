#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    double x,y,n;
    cin>>x>>y>>n;
    cout<<ceil(y/x)<<endl;
    cout<<floor(y/x)<<endl;
    cout<<n-ceil(y/x);
    return 0;
}
