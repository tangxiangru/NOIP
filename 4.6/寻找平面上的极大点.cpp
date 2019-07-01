#include <stdio.h>
#include <stdlib.h> 
struct point{
    int x;
    int y;
};
struct point s[101],save[101];
int saveNum=0;//saveNum=当前栈元素个数
int cmd(const void *a,const void *b)
{
    return (*(struct point *)a).x-(*(struct point *)b).x;
}
void replace(struct point a)
{
    save[saveNum-2]=a;
    saveNum--; 
}
int main()
{
    int n,i,j;  
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&s[i].x,&s[i].y);
    qsort(s,n,sizeof(struct point),cmd);
    for(i=0;i<n;i++)
    {
        save[saveNum]=s[i]; 
        saveNum++;//预入栈 
        while(((saveNum-1)!=0)&&s[i].y>=save[saveNum-2].y)//把自己能统治的点都要了 
            replace(s[i]);
        if(((saveNum-1)!=0)&&save[saveNum-2].x==s[i].x&&save[saveNum-2].y>=s[i].y)//排除y相等的点 
            saveNum--;
    }
    if(saveNum>0)
    {
        printf("(%d,%d)",save[0].x,save[0].y);
        for(i=1;i<saveNum;i++)
            printf(",(%d,%d)",save[i].x,save[i].y);
    }
    return 0;
}
