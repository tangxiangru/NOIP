#include "iostream"
#include <cstdio>
#include <vector>
#include <algorithm>
#include "cstring"
using namespace std;
int main() {
	char s[10000];
	cin.getline(s, 10000);
	int len = 0;
	int Max = 0;
	char s1[201];
	char result[201];
	char ans[201];
	int Min = 1 << 30;
	for (int i = 0; s[i]; i++) {
		if ((s[i] != ' ') && (s[i] != ',')) {
			int k = i;
			int j = 0;
			len = 0;
			for (; ((s[k] != ' ') && (s[k] != ',') && s[k]); k++, j++) {
				s1[j] = s[k];
				len++;
				i = k;
			}
			if (len > Max) {
				s1[j] = '\0';
				strcpy(result, s1);
				Max = len;
			}
			if (len < Min) {
				s1[j] = '\0';
				strcpy(ans, s1);
				Min = len;
			}
		}
	}
	cout << result << endl;
	cout << ans << endl;
	return 0;
}
