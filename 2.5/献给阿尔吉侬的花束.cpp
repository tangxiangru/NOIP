#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//http://bailian.openjudge.cn/tm201402/D/
//非常正常的一个找迷宫最短路径的题目，一定记得在if里面那些判断条件一个不要少 
const int INF=10000;
typedef pair<int,int> p;
int t,r,c,d[220][220],sx,sy,ex,ey,res;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char a[220][220];
int f(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            d[i][j]=INF;
        }
    }
    queue<p> q;
    q.push(p(sx,sy));
    d[sx][sy]=0;
    while(!q.empty()){
        p t=q.front();q.pop();
        int x=t.first,y=t.second;
        for(int i=0;i<4;i++){
            int x2=x+dx[i],y2=y+dy[i];
            if(x2>=0&&x2<r&&y2>=0&&y2<c&&a[x2][y2]!='#'&&d[x2][y2]==INF){
                d[x2][y2]=d[x][y]+1;
                q.push(p(x2,y2));
            }
        }
    }
    return d[ex][ey];
}
int main(){
    cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
                if(a[i][j]=='S'){
                    sx=i;sy=j;
                }
                if(a[i][j]=='E'){
                    ex=i;ey=j;
                }
            }
        }
        res=f();
        if(res!=INF){
            cout<<res<<endl;
        }
        else cout<<"oop!"<<endl;
    }
}
