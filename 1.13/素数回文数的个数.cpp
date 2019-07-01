#include<iostream>
using namespace std;
//http://noi.openjudge.cn/ch0113/05/
//数据范围小，所以可以用这样的枚举，判断回文数是转化为char数组再判断的 
//看了别人的，发现可以直接把整数x反转成另一个整数，然后比较这两个整数是否相等 
int n,cnt=0;
bool is_prime[1100];
bool is_hw(int x){
    char a[10];
    int k=0,l,r;
    while(x>0){
        a[k++]=x%10;
        x/=10;
    }
    l=0;r=k-1;
    while(l+1<=r){
        if(a[l]!=a[r]){
            return false;
        }
        l++;r--;
    }
    return true;
}
int main(){
    while(cin>>n){

    for(int i=2;i<=n;i++)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            for(int j=2*i;j<=n;j=j+i)is_prime[j]=false;
            if(i>=11){
                if(is_hw(i)){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
}
}
