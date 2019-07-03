#include<iostream>
#include<cstring>
using namespace std;
int main(){
int n;
cin>>n;
for (int i=1;i<=n;i++){
char st[100]; int k;
cin>>st>>k;
for (int j=0;j<strlen(st)-1;j++)
if (st[j]>st[j+1]) {st[j]='0';
k--;
if (j!=0){
int m=j-1;
while(st[m]>st[j+1]&&m>=0){
st[m]='0';
k--;
if (k==0) break;
m--;
}
}
if (k==0) break;
}
for (int j=0;j<strlen(st)-k;j++)
if (st[j]!='0') cout<<st[j];
cout<<endl;
}
return 0;
}
