#include "iostream"
#include "iomanip"
using namespace std;
int main() {
    float sum = 0;
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        //1/1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + 1/7 - 1/8 + ... + (-1)n-1·1/n
        if(i%2==1)
            sum += 1/(float)i;
        else
            sum -= 1/(float)i;
    }
    cout<<fixed<<setprecision(4)<<sum;
}
