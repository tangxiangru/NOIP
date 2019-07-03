#include <bits/stdc++.h>

using namespace std;

int main(){
int i,n,k,p,len=0,t=1;
queue<int> card;
priority_queue<int,vector<int>,greater<int> > a;

scanf("%d%d%d",&n,&k,&p);

for (i=1;i<=k;i++){
card.push(i);
}

while (!card.empty()){
if (t%n==0) {
a.push(card.front());
card.pop();
}
else card.pop();
if (card.empty()) break;
for (i=1;i<=p;i++){
card.push(card.front());
card.pop();
}
t++;
}

while (!a.empty()){
printf("%d\n",a.top());
a.pop();
}

return 0;

}
