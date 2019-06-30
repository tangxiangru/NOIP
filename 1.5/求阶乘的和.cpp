#include "iostream"
#include "iomanip"
using namespace std;
int getFactorial(int k)
{
    int result = 1;
    for(int i=1;i<=k;i++)
    {
        result*=i;
    }
    return result;
}
int main() {
    int sum = 0;
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        sum+=getFactorial(i);
    }
    /*N 取值范围是2~11 因此sum最大值为43954713，在int的范围内*/
    cout<<sum;
//    cout<<INT_MAX<<endl;
}
