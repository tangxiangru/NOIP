#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    string words[100];
    int num = 0;
    while (cin >> words[num]){
        bool has = false;
        for (int i=0; i<num; i++){
            if (words[i].compare(words[num]) == 0){
                has = true;
                break;
            }
        }
        if (!has) num++;
    }
    sort(words, words+num);
    for (int i=0; i<num; i++){
        cout << words[i] << endl;
    }
    return 0;
}
