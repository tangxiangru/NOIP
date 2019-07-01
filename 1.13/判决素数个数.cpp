#include<iostream>
using namespace std;
//http://noi.openjudge.cn/ch0113/10/
//数目比较小可以枚举，但是注意枚举到i的平方根即可 
int x,y,res=0,flag;
int main(){
    int a,b;
    cin>>a>>b;
    x=min(a,b);
    y=max(a,b);
    for(int i=x;i<=y;i++){
        flag=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(i!=1&&flag){
            res++;
        }
    }
    cout<<res<<endl;
}
