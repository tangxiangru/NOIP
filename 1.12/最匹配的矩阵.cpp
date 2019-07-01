#include<cstdio>
#include<climits>
#include<iostream>
using namespace std;
#define N 105
int m,n,r,s;
int a[N][N],b[N][N];
int minv,ansi,ansj;
inline int abs(int x){
    return x<0?x*(-1):x;
}
inline int calc(int x,int y){
    int v=0;
    for(int i=x;i<x+r;i++)
        for(int j=y;j<y+s;j++)
            v+=abs(a[i][j]-b[i-x][j-y]);
    return v;
}
inline void print(int x,int y){
    for(int i=x;i<x+r;i++){
        for(int j=y;j<y+s;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d",&r,&s);
    for(int i=0;i<r;i++)
        for(int j=0;j<s;j++)
            scanf("%d",&b[i][j]);
    minv=INT_MAX;
    for(int i=1;i<=m-r+1;i++)
        for(int j=1;j<=n-s+1;j++)
            if(minv>calc(i,j)) ansi=i,ansj=j,minv=calc(i,j);
    print(ansi,ansj);
}
