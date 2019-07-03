#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
int cengshu = 0;
vector<string>result;
void processdir(string dir) {
	string input;
	set<string>files;
	set<string>::iterator it;
	for (int i = 0; i < cengshu; i++) {
		result.push_back("|     ");
	}
	result.push_back(dir + "\n");
	while (cin >> input) {
		if (input[0] == ']') {
			if (files.size()) {
				it = files.begin();
				while(it!=files.end())
				{
					for (int i = 0; i < cengshu; i++) {
						result.push_back("|     ");
					}
					result.push_back(*it+"\n");
					it++;
				}
			}
			cengshu--;
			break;
		}
		else if (input[0] == 'd') {
			cengshu++;
			processdir(input);
		}
		else if (input[0] = 'f') {
			files.insert(input);
		}
	}
}
void print() {
	for (int i = 0; i < result.size()-2; i++) {
		cout << result[i];
	}
}
int num = 1;
int main() {
	string s;
	set<string>files;
	set<string>::iterator it;
	result.push_back("DATA SET " + to_string(num) + ":\n");
	num++;
	result.push_back("ROOT\n");
	while (cin >> s) {
		if (s == "#")
			break;
		if (s[0] == 'f') {
			files.insert(s);
		}
		else if (s[0] == 'd') {
			cengshu++;
			processdir(s);
		}
		else if (s[0] == '*') {
			if (files.size()) {
				it = files.begin();
				while (it != files.end())
				{
					result.push_back(*it+"\n");
					it++;
				}
			}
			files.clear();
			result.push_back("\nDATA SET " + to_string(num) + ":\n");
			num++;
			result.push_back("ROOT\n");
		}
	}
	print();
	return 0;
}
