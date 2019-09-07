#include <stdio.h>
#include <string.h>
int main()
{
      char a[105];
      int i,l;
      while(scanf("%s",a)!=EOF)//多组输入
      {
          l=strlen(a);//取字符串长度
          for(i=0;i<l/2;i++)
          {
              if(a[i]!=a[l-i-1]) {printf("no\n");break;}//对称位不等，不是回文，退出循环
          }
          if(i>=l/2) printf("yes\n");//对比次数大于字符串长一半，是回文
      }
      return 0;
}
