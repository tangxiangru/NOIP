#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int d[110][110]={0},d1[110][110]={0};//d1位控制变换用的
int n,m;
int i,j;
char work[200];
int k;

void A()//操作A
{
    int i,j;
    memset(d,0,sizeof(d));
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
                d[j][m-i+1]=d1[i][j];
    int temp=m;
    m=n;
    n=temp;
    memset(d1,0,sizeof(d1));
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
                d1[i][j]=d[i][j];
    //cout<<"A is right"<<endl;         
}

void B()//操作B，逆时针旋转90°就相当于顺时针旋转270°
{
    A();
    A();
    A();
    //cout<<"B is right"<<endl;     
}

void C()//操作C
{
    int i,j;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
                d[i][j]=d1[i][n-j+1];
    memset(d1,0,sizeof(d1));
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
                d1[i][j]=d[i][j];

    //cout<<"C is right"<<endl;     
} 

void D()//操作D
{
    int i,j;
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
                d[i][j]=d1[m-i+1][j];
    memset(d1,0,sizeof(d1));
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
                d1[i][j]=d[i][j];
    //cout<<"D is right"<<endl;     
}

int main()
{
    scanf("%d%d",&m,&n);
    for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
            {
                scanf("%d",&d[i][j]);
                d1[i][j]=d[i][j];
            }
        cin>>work;
        int k=strlen(work);
        //cout<<k;
        for (i=0;i<k;i++)   
          { 
            if (work[i]=='A')
                A();
            if (work[i]=='B')
                B();
            if (work[i]=='C')
                C();
            if (work[i]=='D')
                D();
          }
    for (i=1;i<=m;i++)
        {
            for (j=1;j<=n;j++)
                printf("%d ",d[i][j]);
            printf("\n");
        }
  return 0;
}    
