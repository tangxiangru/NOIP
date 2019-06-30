#include <iostream>
using namespace std;
int main()
{
    int n, i, x, table[20001]={0};
    cin >> n;
    for (i=0; i<n; i++){
        cin >> x;
        table[x]++;
        if (table[x] == 1){
            cout << x << " ";
        }
    }
    cout << endl;
    return 0;
}
