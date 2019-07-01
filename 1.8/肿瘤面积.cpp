#include<iostream>
using namespace std;
int n,a[1001][1001];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      cin>>a[i][j];
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(!a[i][j])
       {
           int x=i,y=j;
           while(x<=n)
           {
               x++; 
            if(a[x][j]) break;
          }
          x--;//前面x先++，在判断，所以break时x是已经超出边界或不符合条件的，所以要减1
          while(y<=n)
          {
              y++;
              if(a[i][y]) break; 
          }
          y--;//减1的原理同上 
          int tot=(x-i+1)*(y-j+1);//总共的像素点 
          int bian=(x-i+y-j)*2;//边缘上的像素点 
          cout<<tot-bian;
          return 0;
       }
}
