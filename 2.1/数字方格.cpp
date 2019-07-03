#include<bits/stdc++.h>
using namespace std;
int A[105];
int main(){
int n,i,j,k;
scanf("%d",&n);
for(i=1;i<=n;i++){
for(j=1;j<=n;j++){
for(k=1;k<=n;k++){
if((i+j)%2==0&&(j+k)%3==0&&(i+j+k)%5==0)A[i]=i+j+k;//无比暴力的方法，相信应该看得懂
}
}
}
sort(A+1,A+n+1);//有同志会问，你又不知道它有几个A[i]，怎么敢用sort排序呢？其实啊，sort排序是可以的，即使数组A[i]里有很多个0，但在排序时都被排到前面去了，我们只要取最大，最后面的那个数A[n]就好了啊，是吧？可以理解吧？
cout<<A[n]<<endl;
return 0;
}
