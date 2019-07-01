#include<iostream>
#include <cstdlib>
#include<string>
using namespace std;

int check(int k, int y) {
if (2 * k + 1 == y || 3 * k + 1 == y) return true;
else if (2 * k + 1 > y && 3 * k + 1 > y) return false;
else return check(2 * k + 1, y)||check(3 * k + 1, y);
}
int main() {
string str1 = "", str = "";
int unsigned num1 = 0;
int num2 = 0, temp = 0;

getline(cin, str1);
for (char i:str1) if (i != ' ') str += i;
for (int i = 0; i < str.length(); i++)
if (str[i] == ','|| str[i] == '，') {temp = i; break;}

num1 = atoi(str.substr(0, temp).c_str());
num2 = atoi(str.substr(temp + 1, str.length()).c_str());

check(num1, num2) || num1 == num2 ? cout << "YES" << endl : cout << "NO" << endl;
}
