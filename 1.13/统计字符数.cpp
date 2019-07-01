#include<stdio.h>
int main()
{
    int n,i,ans[26];//数组对应保存26个字母出现的次数 
    char str[1005];
    int j,k;
    int maxI;//保存数组ans当中最大值的下标。 
    freopen("5.in","r",stdin);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        for(j=0;j<26;j++)
            ans[j]=0;
        for(j=0;str[j]!='\0';j++)
        {
            k=str[j]-'a';
            ans[k]++;
        }
        maxI=0;
        for(j=1;j<26;j++)
        {
            if(ans[j]>ans[maxI])  maxI=j;
        }
        printf("%c %d\n",'a'+maxI,ans[maxI]);
    }
    return 0;
}
