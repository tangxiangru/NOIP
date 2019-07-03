#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int visited[1000010];
struct Step{
int x;
int steps;
Step(int _x, int _s):x(_x),steps(_s){}
};

queue<Step> q;

int main(){
std::ios::sync_with_stdio(false);
int n;
cin >> n;
while (n--) {
int s, t;
cin >> s >> t;
memset(visited, 0, sizeof(visited));
q.push(Step(s, 0));
visited[s] = 1;
while (!q.empty()) {
Step s= q.front();
if(s.x == t) {
cout << s.steps * 2 << endl;
break;
} else {
if(s.x-1 >= 0 && !visited[s.x-1]) {
q.push(Step(s.x-1, s.steps+1));
visited[s.x-1] = 1;
}
if(s.x+1 <= 1000000 && !visited[s.x+1]) {
q.push(Step(s.x+1, s.steps+1));
visited[s.x+1] = 1;
}
if(s.x*2 <= 1000000 && !visited[s.x*2]) {
q.push(Step(s.x*2, s.steps+1));
visited[s.x*2] = 1;
}
if(s.x%2 ==0 && !visited[s.x/2]) {
q.push(Step(s.x/2, s.steps+1));
visited[s.x/ 2] = 1;
}
q.pop();
}
}
while (!q.empty())
q.pop();
}
return 0;
}
