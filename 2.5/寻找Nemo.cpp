using namespace std;
#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<memory.h>

#define MAXSIZE 200

#define In(x,y) (x>=0 && x<MAXSIZE && y>=0 && y<MAXSIZE)

struct XY {
int x, y;
XY() {}
XY(int a, int b) :x(a), y(b) {}
};

unsigned char door[4] = { 0x80, 0x40, 0x20, 0x10 };// 分别代表 东 南 西 北 门
unsigned char wall[4] = { 0x08, 0x04, 0x02, 0x01 };// 分别代表 东 南 西 北 墙
int orient[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
unsigned char maze[MAXSIZE][MAXSIZE];//迷宫
int visited[MAXSIZE][MAXSIZE];//记录需要穿过的门数，其实可以不用
bool visitflag[MAXSIZE][MAXSIZE];//true 为可以访问
int M, N;
int myendx, myendy;
queue<XY> qlist_curstep;//当前步的队列
queue<XY> qlist_nextstep;//下一步的队列
int curstep;//记录当前步

void setBoundary();
void BFS();

//#define cin fin
//fstream fin("1.txt");

int main() {
while (cin >> M >> N) {
if (M == -1 && N == -1) {
break;
}
memset(visited, -1, sizeof(visited));
memset(visitflag, true, sizeof(visitflag));
memset(maze, 0, sizeof(maze));
setBoundary();
while (!qlist_curstep.empty()) qlist_curstep.pop();
while (!qlist_nextstep.empty()) qlist_nextstep.pop();
int x, y, d, t;
//输入及处理
for (int i = 0; i < M; ++i) {
cin >> x >> y >> d >> t;
for (int j = 0; j < t; ++j) {
if (d == 0) {//横墙
maze[x + j][y] |= wall[1];//南墙
maze[x + j][y - 1] |= wall[3];//北墙
}
else {//竖墙
maze[x][y + j] |= wall[2];//西墙
maze[x - 1][y + j] |= wall[0];//东墙
}
}
}
for (int i = 0; i < N; ++i) {
cin >> x >> y >> d;
if (d == 0) {//横门
maze[x][y] |= door[1];//南门
maze[x][y - 1] |= door[3];//北门
}
else {//竖门
maze[x][y] |= door[2];//西门
maze[x - 1][y] |= door[0];//东门
}
}
float f1, f2;
cin >> f1 >> f2;
myendx = (int)f1;
myendy = (int)f2;
if (!In(myendx,myendy)) {//Nemo位置可能不在迷宫里!!!
printf("0\n");
}
else {
curstep = 0;
qlist_curstep.push(XY(0, 0));
BFS();
printf("%d\n", visited[myendx][myendy]);
}

}
system("pause");
return 0;
}

void setBoundary() {
for (int i = 0; i < MAXSIZE; ++i) {//四边设墙
maze[i][0] = 0x04;
maze[i][MAXSIZE - 1] = 0x01;
maze[0][i] = 0x02;
maze[MAXSIZE - 1][i] = 0x08;
}
maze[0][0] = 0x06;//四角设墙
maze[0][MAXSIZE - 1] = 0x03;
maze[MAXSIZE - 1][0] = 0x0c;
maze[MAXSIZE - 1][MAXSIZE - 1] = 0x09;
return;
}

void BFS() {
do
{
while (!qlist_curstep.empty()) {
int tempx = qlist_curstep.front().x;
int tempy = qlist_curstep.front().y;
qlist_curstep.pop();
visited[tempx][tempy] = curstep;
for (int i = 0; i < 4; ++i) {
if ((maze[tempx][tempy] & wall[i]) == 0) {//没有墙
if (visitflag[tempx + orient[i][0]][tempy + orient[i][1]]) {
qlist_curstep.push(XY(tempx + orient[i][0], tempy + orient[i][1]));
visitflag[tempx + orient[i][0]][tempy + orient[i][1]] = false;
}
}
if (((maze[tempx][tempy] & wall[i]) != 0) && ((maze[tempx][tempy] & door[i]) != 0)) {//有墙但有门
if (visitflag[tempx + orient[i][0]][tempy + orient[i][1]]) {
qlist_nextstep.push(XY(tempx + orient[i][0], tempy + orient[i][1]));
visitflag[tempx + orient[i][0]][tempy + orient[i][1]] = false;
}
}
}
}
curstep++;
qlist_curstep = qlist_nextstep;
while (!qlist_nextstep.empty()) qlist_nextstep.pop();
} while (!qlist_curstep.empty());

return;
}
