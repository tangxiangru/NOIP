#include<stdio.h>
struct person
{
    int no;//病人的编号 
    float num;//病人病情严重程度 
};
int main()
{
    struct person p[55];//表示重症病人的结构体数组 
    int m;//m个病人 
    float a;//入住重症病房的最低严重值 
    int i;//循环变量 
    int n;//临时变量，表示当前输入的病人的编号 
    float t;//临时变量，表示当前输入的病人的严重值 
    int len=0;//表示当前已经遇到的重症病人的人数 
    int j,flag;
    struct person temp;
    freopen("5.in","r",stdin);
    scanf("%d%f",&m,&a);
    for(i=0;i<m;i++)//读入m个人的信息并确定是否重症病人，即：是否需保存其信息 
    {
        scanf("%d%f",&n,&t);//读入病人的编号和严重值 
        if(t>a)
        {
            p[len].no=n;
            p[len].num=t;
            len++;
        }
    }
     if(len==0)//假如没有重症病人 
    {
        printf("None.\n");
        return 0;
    }
    for(i=1;i<len;i++)//对重症病人按严重值排序 ，冒泡算法 
    {
        flag=1;
        for(j=0;j<len-i;j++)
        {
            if(p[j].num<p[j+1].num) 
            { 
                flag=0;
                temp=p[j]; 
                p[j]=p[j+1]; 
                p[j+1]=temp; 
            }
        }
        if(flag)  break;  //if(flag==1)  break;
    }
    for(i=0;i<len;i++)//按重症病人的严重值由大到小输出他们的信息。 
    {
        printf("%03d %.1f\n",p[i].no,p[i].num);
    }
    return 0;
}
