#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i=0; i<s1.size(); i++){
        if (s1[i]>='A'&&s1[i]<='Z') s1[i] -= 'A'-'a';
    }
    for (int i=0; i<s2.size(); i++){
        if (s2[i]>='A'&&s2[i]<='Z') s2[i] -= 'A'-'a';
    }
    int x = s1.compare(s2);
    if (x == 0) cout << "=" << endl;
    else if (x > 0) cout << ">" << endl;
    else cout << "<" << endl;
    return 0;
}
