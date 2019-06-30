#include<cstdio>
#include<cstring>
int ch[450],len,sch[23][23]; //分别为转换后的2进制串，2进制串的位数，填入后的二维数组
bool chs[23][23]; //辅助二维数组
void ten_two(char); //2进制转换的函数
void strue(int,int); //辅助二维数组的初始化函数
int main()
{
    int r,c;
    char s[100]={};
    scanf("%d%d%*c",&r,&c);
    strue(r,c);
    gets(s);
    for(int i=0;i<strlen(s);i++) //转换
        ten_two(s[i]);
    int x=0,y=0,tot=0,lx=1;
    while(tot<r*c)
    {
        switch(lx)
        {
            case 1: //向左
                if(!chs[x][y+1] || y==c-1) //转向条件
                {
                    lx=2;
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    x++;
                    tot++;
                }
                else
                {
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    y++;
                    tot++;
                }
                break;
            case 2: //向下
                if(!chs[x+1][y] || x==r-1) //转向条件
                {
                    lx=3;
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    y--;
                    tot++;
                }
                else
                {
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    x++;
                    tot++;
                }
                break;
            case 3: //向右
                if(!chs[x][y-1] || y==0) //转向条件
                {
                    lx=4;
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    x--;
                    tot++;
                }
                else
                {
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    y--;
                    tot++;
                }
                break;
            case 4: //向上
                if(!chs[x-1][y] || x==0) //转向条件
                {
                    lx=1;
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    y++;
                    tot++;
                }
                else
                {
                    sch[x][y]=ch[tot];
                    chs[x][y]=false;
                    x--;
                    tot++;
                }
                break;
        }
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            printf("%d",sch[i][j]);
    return 0;
}
void ten_two(char c)
{
    int i=0,op=c-'A'+1,x[5]={};
    while(i<5)
    {
        x[i]=op%2;
        op/=2;
        i++;
    }
    for(int js=4;js>=0;js--,len++)
        ch[len]=x[js];
}
void strue(int r,int c)
{
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            chs[i][j]=true;
}
