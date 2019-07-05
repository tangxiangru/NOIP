#include <iostream>
#define Max 1000005
using namespace std;
int a[Max]; 
//直接递归Time Limit Exceeded 
//那就记忆化递归 
int f(int k){
    if(a[k]!=0) return a[k];
    else if(k==1) return 1;
    else if(2==k) return 2;
    else return a[k]=(2*(f(k-1)%32767)+f(k-2)%32767)%32767;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        cout<<f(a)<<endl;
    }
    return 0;
}
