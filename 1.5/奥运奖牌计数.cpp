#include<bits/stdc++.h>
using namespace std;
int main(){
	int j,y,t,n,totj=0,toty=0,tott=0,tot=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>j>>y>>t;
		totj+=j;toty+=y;tott+=t;
		tot+=j+y+t; 
	}
	cout<<totj<<" "<<toty<<" "<<tott<<" "<<tot;
	return 0;
}
