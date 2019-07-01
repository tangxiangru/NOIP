#include<bits/stdc++.h>
using namespace std;
char a[1000];
int b[1000],n,i=0,j=0,k=1;
int main() {
gets(a);
n=strlen(a);
for(int i=0; i<n; i++) {
if(a[i]>='0'&&a[i]<='9')
b[k]=b[k]*10+a[i]-'0';
else if(a[i-1]>='0'&&a[i-1]<='9')
k++;
}
if(a[n-1]>='0'&&a[n-1]<='9')
k++;
sort(b,b+k);
cout<<b[1];
for(int i=2; i<k; i++)
cout<<","<<b[i];
}
