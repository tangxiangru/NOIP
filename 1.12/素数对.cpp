#include<iostream>
using namespace std;
//http://noi.openjudge.cn/ch0112/10/
//埃氏筛法，挑战程序设计P119
const int N=11000;
int n,flag=0;
bool is_prime[N];
int main(){
    cin>>n;
    for(int i=2;i<=n;i++)is_prime[i]=true;
    is_prime[0]=false;is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            for(int j=2*i;j<=n;j=j+i){
                is_prime[j]=false;
            }
            if(is_prime[i-2]){
                flag=1;
                cout<<i-2<<" "<<i<<endl;
            }
        }
    }
    if(flag==0)cout<<"empty"<<endl;
}
