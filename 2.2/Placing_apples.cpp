#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int ans;

int dfs(int m, int n){
    if(m==1 || n==1) return 1;
    if(m<n) return dfs(m, m);
    else if(m==n) return 1+dfs(m, m-1);
    else return dfs(m, n-1) + dfs(m-n, n);
}

int main(){
    int t, m, n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        cout<<dfs(m, n)<<endl;
    }
    return 0;
}

