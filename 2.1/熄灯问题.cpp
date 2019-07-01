#include<iostream>
using namespace std;
//http://noi.openjudge.cn/ch0201/1813/
//感觉很难，关键是如何想到这么简便的方法呢 
int pu[8][8],pr[8][8];
bool guess(){
    for(int i=1;i<5;i++){
        for(int j=1;j<7;j++){
            pr[i+1][j]=(pu[i][j]+pr[i][j]+pr[i-1][j]+
                        pr[i][j-1]+pr[i][j+1])%2;
        }
    }
    for(int j=1;j<7;j++){
        if((pr[5][j]+pr[5][j-1]+pr[5][j+1]+pr[4][j])%2!=pu[5][j]){
            return false;
        }
    }
    return true;
}
void enumerate(){
    //模拟二进制的进位加法 
    int c;
    bool s;
    for(c=1;c<7;c++){
        pr[1][c]=0;
    }
    while(!guess()){
        pr[1][1]++;
        c=1;
        while(pr[1][c]>1){
            pr[1][c]=0;
            c++;
            pr[1][c]++;
        }
    }
    return;
}
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=6;j++){
            cin>>pu[i][j];
        }
    }
    //枚举第一行
    enumerate();
    for(int i=1;i<=5;i++){
        for(int j=1;j<=6;j++){
            cout<<pr[i][j]<<" ";
        }
        cout<<endl;
    }
}
