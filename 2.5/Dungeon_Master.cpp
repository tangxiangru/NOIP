#include<iostream>
#include<queue>
using namespace std;
//http://noi.openjudge.cn/ch0205/1253/
struct node{
    int x,y,z;
};
const int INF=10000;
int l,r,c,d[50][50][50],sx,sy,sz,ex,ey,ez,res;
char a[50][50][50];
node s,t,e;
int dx[]={0,1,0,-1,0,0},dy[]={1,0,-1,0,0,0},dz[]={0,0,0,0,1,-1};
void f(){
    queue<node> q;
    s.x=sx;s.y=sy;s.z=sz;
    q.push(s);
    d[sx][sy][sz]=0;
    while(!q.empty()){
        t=q.front();q.pop();
        int x=t.x,y=t.y,z=t.z;
        for(int i=0;i<6;i++){
            int x2=x+dx[i],y2=y+dy[i],z2=z+dz[i];
            if(x2>=0&&x2<l&&y2>=0&&y2<r&&z2>=0&&z2<c&&a[x2][y2][z2]!='#'&&d[x2][y2][z2]==INF){
                d[x2][y2][z2]=d[x][y][z]+1;
                e.x=x2;e.y=y2;e.z=z2;
                q.push(e);
            }
        }
    }
    res=d[ex][ey][ez];
}
int main(){
    while(cin>>l>>r>>c){
        if(l==0&&r==0&&c==0)break;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin>>a[i][j][k];
                    d[i][j][k]=INF;
                    if(a[i][j][k]=='S'){
                        sx=i;sy=j;sz=k;
                    }
                    if(a[i][j][k]=='E'){
                        ex=i;ey=j;ez=k;
                    }
                }
            }
        }
        f();
        if(res==INF){
            cout<<"Trapped!"<<endl;
        }
        else cout<<"Escaped in "<<res<<" minute(s)."<<endl;
    } 
}
