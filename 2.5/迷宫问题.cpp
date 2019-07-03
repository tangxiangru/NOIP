#include <iostream>
using namespace std;

const int nxt[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[6][6], book[6][6], con[36][2], path[36][2], MIN = 100000000;

void dfs(int x, int y, int step){
if (x == 4 && y == 4){
if (step < MIN){
MIN = step;
for (int i = 0; i < MIN; ++i){
path[i][0] = con[i][0];
path[i][1] = con[i][1];
}
}
return ;
}
for (int i = 0; i <= 3; ++i){
int tx = x + nxt[i][0], ty = y + nxt[i][1];
if (tx < 0 || tx > 4 || ty < 0 || ty > 4)
continue;
if (a[tx][ty] == 0 && book[tx][ty] == 0){
book[tx][ty] = 1;
con[step][0] = tx, con[step][1] = ty;
dfs(tx, ty, step + 1);
book[tx][ty] = 0;
}
}
}

int main(){
ios_base::sync_with_stdio(0);
for (int i = 0; i <= 4; ++i)
for (int j = 0; j <= 4; ++j)
cin >> a[i][j];
book[0][0] = con[1][0] = con[1][1] = 1;
dfs(0, 0, 1);
for (int i = 0; i < MIN; ++i)
cout << '(' << path[i][0] << ", " << path[i][1] << ')' << endl;
return 0;
}
