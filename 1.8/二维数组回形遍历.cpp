#include <stdio.h>
#define maxN 101
int main(int argc, char *argv[])
{
    int row,col,i,j,k;
    int a[maxN][maxN];
    int count;
    
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    if(row==1)//只有一行
    {
        i=0;j=0; 
        for(k=1;k<=col;k++)
        { printf("%d\n",a[i][j]);j++;}
    }
    else if(col==1)//只有一列
    {
        i=0;j=0;
        for(k=1;k<=row;k++)
        { printf("%d\n",a[i][j]);i++;}
    }
    else
    {
        i=0;j=0;
        count=row*col;
        while(count>0)
        {
            for(k=1;k<col;k++)
            { count--; printf("%d\n",a[i][j]);j++;}  //输出一个环的上面那一条边 
            
            for(k=1;k<row;k++)
            { count--; printf("%d\n",a[i][j]);i++;}  //输出一个环的右侧那一条边
            
            for(k=1;k<col;k++)
            { count--; printf("%d\n",a[i][j]);j--;}  //输出一个环的下面那一条边
            
            for(k=1;k<row;k++)
            { count--; printf("%d\n",a[i][j]);i--;}  //输出一个环的左侧那一条边
            
            i++;
            j++;
            row-=2;
            col-=2;
            if(row==1)//只剩下一行
            {
                for(k=1;k<=col;k++)
                { count--; printf("%d\n",a[i][j]);j++;}
            }
            else if(col==1)//只剩下一列
            {
                for(k=1;k<=row;k++)
                { count--; printf("%d\n",a[i][j]);i++;}
            }
        }
    }
    return 0;
}
