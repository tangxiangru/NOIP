#include "iostream"
#include "iomanip"
using namespace std;
int main() {
    float p = 1, q = 2, sum = 0;
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        sum+=q/p;
 
        //qi+1= qi+ pi, pi+1=qi
        float tmp = q;
        q = q + p;
        p = tmp;
    }
    cout<<fixed<<setprecision(4)<<sum;
}
