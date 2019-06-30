#include <iostream>
#include <cstring>
using namespace std;
char convert(char ch, bool first)
{
    if (first){
        if (ch>='a'&&ch<='z'){
            ch -= ('a'-'A');
        }
    }
    else{
        if (ch>='A'&&ch<='Z'){
            ch -= ('A'-'a');
        }
    }
    return ch;
}
int main()
{
    int n;
    string s;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> s;
        cout << convert(s[0], true);
        for (int j=1; j<s.size(); j++){
            cout << convert(s[j], false);
        }
        cout << endl;
    }
    return 0;
}
