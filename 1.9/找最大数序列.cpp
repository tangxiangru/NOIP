#include <iostream>
#include <string>
#include <vector>
using namespace std;
void SplitString(const string& s, vector<string>& v, const string& c)
{
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2){
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}
int main()
{
    string line;
    int n, i, j, x, maxn=0, a[31];
    cin >> n;
    for (i=1; i<=n; i++){
        cin >> line;
        vector<string> v;
        SplitString(line, v, ","); // 按逗号字符来分割
        int max_line = 0;
        for (j=0; j<v.size(); j++){
            x = std::stoi(v[j]);
            if (x > max_line) max_line = x; // 行最大值
            if (x > maxn) maxn = x; // 最大值
        }
        a[i] = max_line;
    }
    cout << maxn << endl;
    bool first = true;
    for (i=1; i<=n; i++){
        if (a[i] == maxn){
            if (!first) cout << ",";
            cout << i;
            first = false;
        }
    }
    cout << endl;
    return 0;
}
