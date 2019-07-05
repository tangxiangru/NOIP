#include<iostream>
using namespace std;
//http://noi.openjudge.cn/ch0108/17/
//类似于搜索的题，但是简单些 
int r,c,res=0,dx[]={0,1,-1,0},dy[]={1,0,0,-1};
char a[200][200];
bool f[200][200];
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            f[i][j]=true;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]=='#'&&f[i][j]){
                res++;
                //cout<<res<<endl;
                for(int k=0;k<4;k++){
                    int x2=i+dx[k],y2=j+dy[k];
                    if(x2>=0&&x2<r&&y2>=0&&y2<c&&a[x2][y2]=='#'){
                        f[x2][y2]=false;
                    }
                }
            }
        }
    }
    cout<<res<<endl;
}
