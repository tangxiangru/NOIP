#include<iostream>
using namespace std;
//http://noi.openjudge.cn/ch0108/21/
int r,c,a[200][200];
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r+c-1;i++){
        int y=i,x=0;//当前的x,y坐标 
        while(y>=c){
            y--;
            x++;
        }
        while(x>=0&&x<r&&y>=0&&y<c){
            cout<<a[x][y]<<endl;
            x++;
            y--;
        } 
    }
}
