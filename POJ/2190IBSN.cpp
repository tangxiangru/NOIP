#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 1000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;
LL dp[1000005];
map<char,int> mp;
void init() {
    mp['0']=0;
    mp['1']=1;
    mp['2']=2;
    mp['3']=3;
    mp['4']=4;
    mp['5']=5;
    mp['6']=6;
    mp['7']=7;
    mp['8']=8;
    mp['9']=9;
    mp['X']=10;
}
int main() {
    init();
    string str;
    cin>>str;
    int x=-1;
    int sum=0;
    for(int i=0; i<10; ++i) {
        if(str[i]!='?')
            sum+=mp[str[i]]*(10-i);
        else
            x=10-i;
    }
    int len=9;
    if(x==1)
        len=10;
    for(int i=0; i<=len; ++i) {
        int temp=sum+x*i;
        if(temp%11==0) {
            if(i==10)
                cout<<'X'<<endl;
            else
                cout<<i<<endl;
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
