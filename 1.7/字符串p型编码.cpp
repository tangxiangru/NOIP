#include<iostream>
#include<string>
using namespace std;
 
int main(){
	string s;
	cin >> s;
	int count = 1;
	s[s.length()] = -1;
	for(int i = 0; i < s.length(); i++){
		if(s[i] != s[i + 1]){
			cout << count << s[i] - '0' ;
			count = 1;
		}
		else{
			count ++ ;
		}
	}
	return 0;
} 
