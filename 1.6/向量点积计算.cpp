#include "iostream"
using namespace std;

int A[1000];
int B[1000];

int main() {
    int result = 0;
    int Num;
    cin >> Num;
    for(int i = 0 ; i < Num ; i++)
        cin >> A[i];
    for(int i = 0 ; i < Num ; i++)
        cin >> B[i];

    for(int i = 0 ; i < Num ; i++)
    {
        result += A[i]*B[i];
    }
    cout<<result;
    return 0;
}

