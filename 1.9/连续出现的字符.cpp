#include <iostream>
#include <string>
using namespace std;
int main()
{
    char cur;
    string s;
    int k, i, times=0;
    cin >> k >> s;
    cur = s[0];
    for (i=0; i<s.size(); i++){
        if (cur == s[i]){
            times++;
            if (times >= k){
                cout << cur << endl;
                return 0;
            }
        }
        else{
            cur = s[i];
            times = 1;
        }
    }
    cout << "No" << endl;
    return 0;
}
