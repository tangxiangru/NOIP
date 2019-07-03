#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//字符串结构体
typedef struct Log
{
char str[1000];//日志记录
//计算任务开始执行的时间“年-月-日 时：分：秒，毫秒”
int year;//年
int month;//月
int day;//日
int hour;//小时
int minute;//分
int second;//秒
int msecond;//毫秒
double time;//计算任务消耗的时间(以秒计)
}Log;

//排序函数
//时间消耗少的计算任务排在前面，时间消耗多的计算任务排在后面。
//如果两个计算任务消耗的时间相同，则将开始执行时间早的计算任务排在前面。
int cmp(const void *a, const void *b){
struct Log *c = (Log *)a;
struct Log *d = (Log *)b;

if(c->time != d->time){
return c->time > d->time ?1:-1;
}
else if(c->year != d->year){
return c->year - d->year;
}
else if(c->month != d->month){
return c->month - d->month;
}
else if(c->day != d->day){
return c->day - d->day;
}
else if(c->hour != d->hour){
return c->hour - d->hour;
}
else if(c->minute != d->minute){
return c->minute - d->minute;
}
else if(c->second != d->second){
return c->second - d->second;
}
else if(c->msecond != d->msecond){
return c->msecond - d->msecond;
}
}

Log log[10001];

int main()
{
int i,j,n,index = 0;
//freopen("C:\\Users\\SJF\\Desktop\\acm.txt","r",stdin);
while(gets(log[index].str))
{
//最后一行为空行，表示日志结束
if(strcmp(log[index].str,"") == 0){
break;
}
//格式化
sscanf(log[index].str,"%*s%d-%d-%d%d:%d:%d,%d%lf%*s",&log[index].year,&log[index].month,&log[index].day
,&log[index].hour,&log[index].minute,&log[index].second,&log[index].msecond,&log[index].time);
index++;
}
//排序
qsort(log,index,sizeof(log[0]),cmp);
//输出
for(i = 0;i < index;i++){
printf("%s\n",log[i].str);
}
return 0;
}
