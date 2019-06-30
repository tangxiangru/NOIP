#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int cont=1,s=0;
	char a[20],flag;
	cin.getline(a,sizeof(a));
	for(int i=0;i<strlen(a)&&cont<=9;i++){
		if(a[i]=='-') ;
		else {
			int temp=a[i]-'0';
			s+=temp*cont;
			cont++;
		}
	}
	flag=s%11;
	if(flag==10) flag='X';
	else flag=flag+'0';
	if(flag==a[strlen(a)-1]) cout<<"Right";
	else{
		a[strlen(a)-1]=flag;
		cout<<a;
	}
	return 0;
}
