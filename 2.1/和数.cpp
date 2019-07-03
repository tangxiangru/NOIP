#include<bits/stdc++.h>
using namespace std;
int A[105];
int main() {
int n,i,j,k,ans=0;
scanf("%d",&n);
for(i=1; i<=n; i++)
scanf("%d",&A[i]);
for(i=1; i<=n; i++)
for(j=1; j<=n; j++)
for(k=j+1; k<=n; k++)
if(A[i]==A[k]+A[j]) {
ans++;
j=k=n+1;
}
cout<<ans<<endl;
return 0;
}
