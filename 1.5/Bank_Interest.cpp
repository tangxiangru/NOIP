#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int R, M, Y;
    double money;
    cin >> R >> M >> Y;
    money = M;
    for (int i=0; i<Y; i++){
        money *= (100+R)/100.0;
    }
    cout << (int)money << endl;
    return 0;
}
