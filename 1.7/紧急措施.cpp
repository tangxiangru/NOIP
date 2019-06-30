#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
 
using namespace std;
 
int main(){
	int n,ok=1;
	string s;
	cin>>s;
	cin>>n;
	while(n--){
		string s1[3];
		for(int i=0;i<3;i++) cin>>s1[i];
		if(s1[2]==s){
			ok=0;
			for(int i=0;i<s1[1].length();i++){
				char tem=s1[1][i];
				if(tem>='a'&&tem<='z') s1[1][i]=s1[1][i]+'A'-'a';
				else if(tem>='A'&&tem<='Z') s1[1][i]=s1[1][i]+'a'-'A' ;
			}
			cout<<s1[0]<<' '<<s1[1]<<endl;
		}
	}
	if(ok) cout<<"empty"; 
	return 0;
}
