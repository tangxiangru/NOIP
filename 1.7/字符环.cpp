#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int x, y, len, len1, len2, limit, ans=0;
    string s1, s2;
    cin >> s1 >> s2;
    len1 = s1.size();    
    len2 = s2.size();
    limit = min(len1, len2);    //最短字符串的长度
    s1 += s1; // 造环
    s2 += s2; // 造环
    for (int i=0; i<len1; i++){
        for (int j=0; j<len2; j++){
            len = 0;
            x = i;
            y = j;
            while (s1[x++]==s2[y++] && len<limit)     //不能超过段长
                len++;  
            if (len > ans)
                ans = len;
        }
    }
    cout << ans << endl;
    return 0;
}
