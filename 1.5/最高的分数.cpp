#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n, score, top=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> score;
        if (score > top) top = score;
    }
    cout << top << endl;
    return 0;
}
