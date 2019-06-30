#include<iostream>
using namespace std;
//http://noi.openjudge.cn/ch0108/11/
//两种方法，一个是获取输入的时候直接按照输出格式存
//另一个是输出的时候改格式，感觉第二个更直觉，好处理 
int n,m,a[110][110];
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=n-1;j>=0;j--){
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }
}
