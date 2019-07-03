#include <iostream>
using namespace std;
int map[27][27], sx[27], sy[27];
int next_step[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},{1, -2}, {1, 2}, {2, -1}, {2, 1}};
int p, q, b, step;
void search(int i, int j) {
if (b)
return;
int x, y, k;
step++;
sx[step] = i;
sy[step] = j;
if(step == p * q) {
b = 1;
return;
}
map[i][j] = 1;
for (k = 0; k < 8; k++) {
y = j + next_step[k][0];
x = i + next_step[k][1];
if (map[x][y] == 0 && x > 0 && x <= p && y > 0 && y <= q) {
search(x, y);
step--;
}
}
map[i][j] = 0;
}

int main() {
int i, j, n, t = 0;
cin>>n;
while (n--) {
b = 0;
step = 0;
cin>>p>>q;
for (i = 1; i <= p; i++)
for(j = 1; j <= q; j++)
map[i][j] = 0;
search(1, 1);
printf("Scenario #%d:\n", ++t);
if (b) {
for (i = 1; i <= p * q; i++) {
printf("%c%d", sy[i] + 64, sx[i]);
}
printf("\n");
} else {
printf("impossible\n");
}
if (n != 0) printf("\n");
}
return 0;
}

