#include "stdio.h"
#include "math.h"
typedef struct Point
{
double x1,y1,y2,x2,d;
int num;
}Point;
Point p[101];
int a[101];
double ans1[101][101],lastx[101][101],lasty[101][101],ans2[101][101],last1[101][101],last2[101][101];
double MIN,te,tem;
double distance(Point A)
{
double ans;
ans = (A.x1-A.x2)*(A.x1-A.x2) + (A.y1-A.y2)*(A.y1-A.y2);
return sqrt(ans);
}
double dis(double x1,double y1,double x2,double y2)
{
double ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
return sqrt(ans);
}
int main()
{
int T,i,j,k,m,n,t,r;
double xs,xt,ys,yt;
scanf("%d",&T);
while(T--)
{
scanf("%lf%lf%lf%lf",&xs,&ys,&xt,&yt);
scanf("%d",&m);
for(i = 1; i <= m; i ++) scanf("%d",&a[i]);
scanf("%d",&n);
for(i = 1; i <= n; i ++)
{
scanf("%lf%lf%lf%lf%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2,&p[i].num);
p[i].d = distance(p[i]);
}
k = 0;
for(i = 1; i <= n; i ++)
{
if(p[i].num == a[1])
{
k ++;
ans1[1][k] = dis(xs,ys,p[i].x2,p[i].y2) + p[i].d;

lastx[1][k] = p[i].x1;
lasty[1][k] = p[i].y1;

ans2[1][k] = dis(xs,ys,p[i].x1,p[i].y1) + p[i].d;

last1[1][k] = p[i].x2;
last2[1][k] = p[i].y2;
}
}
t = k;
for(i = 2; i <= m; i ++)
{
k = 0;
for(j = 1; j <= n; j ++)
{
if(p[j].num == a[i])
{
k ++;
ans1[i][k] = ans1[i-1][1] + dis(lastx[i-1][1],lasty[i-1][1],p[j].x2,p[j].y2) + p[j].d;
te = ans2[i-1][1] + dis(last1[i-1][1],last2[i-1][1],p[j].x2,p[j].y2) + p[j].d;
if(te < ans1[i][k]) ans1[i][k] = te;

lastx[i][k] = p[j].x1;
lasty[i][k] = p[j].y1;

for(r = 2; r <= t; r ++)
{
te = ans1[i-1][r] + dis(lastx[i-1][r],lasty[i-1][r],p[j].x2,p[j].y2) + p[j].d;
tem = ans2[i-1][r] + dis(last1[i-1][r],last2[i-1][r],p[j].x2,p[j].y2) + p[j].d;
if(te > tem) te = tem;
if(te < ans1[i][k]) ans1[i][k] = te;
}
//
ans2[i][k] = ans1[i-1][1] + dis(lastx[i-1][1],lasty[i-1][1],p[j].x1,p[j].y1) + p[j].d;
te = ans2[i-1][1] + dis(last1[i-1][1],last2[i-1][1],p[j].x1,p[j].y1) + p[j].d;
if(te < ans2[i][k]) ans2[i][k] = te;

last1[i][k] = p[j].x2;
last2[i][k] = p[j].y2;

for(r = 2; r <= t; r ++)
{
te = ans1[i-1][r] + dis(lastx[i-1][r],lasty[i-1][r],p[j].x1,p[j].y1) + p[j].d;
tem = ans2[i-1][r] + dis(last1[i-1][r],last2[i-1][r],p[j].x1,p[j].y1) + p[j].d;
if(te > tem) te = tem;
if(te < ans2[i][k]) ans2[i][k] = te;
}

}
}
t = k;
}
for(i = 1; i <= t; i ++)
{
ans1[m][i] += dis(lastx[m][i],lasty[m][i],xt,yt);
ans2[m][i] += dis(last1[m][i],last2[m][i],xt,yt);
}
// for(i = 1; i <= t; i ++)
// printf("%.6lf %lf\n",ans1[m][i],ans2[m][i]);
MIN = ans1[m][1];
if(MIN > ans2[m][1]) MIN = ans2[m][1];
for(i = 2; i <= t; i ++)
{
if(ans1[m][i] < MIN) MIN = ans1[m][i];
if(ans2[m][i] < MIN) MIN = ans2[m][i];
}
printf("%.12lf\n",MIN);
}
return 0;
}

