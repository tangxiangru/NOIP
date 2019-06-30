#include<iostream>
#include<string>
using namespace std;
 
int main(){
	string s;
	getline(cin, s);
	s[s.length()] = ' ';
	int count = 1;
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;
		}
	}
	for(int i = 0; i < s.length(); i++){
		if(s[i] != s[i+1]){
				cout << "(" << s[i] << "," << count << ")" ;
				count = 1;
			}
		
		else
		{
			count ++ ;
		}
	}
	return 0;
} 
