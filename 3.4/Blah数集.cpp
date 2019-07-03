#include<bits/stdc++.h>
using namespace std;
int qa[100005],qb[100005],head1=0,head2=0;
int a,n,x,tail1=0,tail2=0;
int main(){
while(cin>>a){
head1=0,head2=0,tail1=0,tail2=0;
cin>>n;
x=a;
qa[tail1++]=2*x+1;
qb[tail2++]=3*x+1;
n--;
while(n--){
if(qa[head1]<qb[head2])
x=qa[head1++];
else
if(qa[head1]>qb[head2])
x=qb[head2++];
else{
x=qa[head1++];
head2++;
}
qa[tail1++]=2*x+1;
qb[tail2++]=3*x+1;
}
cout<<x<<endl;
}

return 0;
}

