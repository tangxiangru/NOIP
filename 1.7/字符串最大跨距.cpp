#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[301],b[11],c[11],t[11];
char s[401];
int p,la,lb,lc,first,endd;
int find(int k,int w)
{
    int j=1,i=k,lt;
    if(w==2) 
    {
      lt=lb;
      for(int r=1;r<=lb;r++) t[r]=b[r];    
    }
    else 
    {
        lt=lc;
        for(int r=1;r<=lc;r++) t[r]=c[r];
    }
    for(;i<=la,j<=lt;i++,j++)
        if(a[i]!=t[j]) return 0;
    if(j-1!=lt) return 0;
    return k;
}
int main()
{
    cin>>s;
    int ls=strlen(s);
    for(int i=0;i<ls;i++)/输入一整行，再断开
    {
        if(s[i]==‘,‘) p++;
        else if(!p) a[++la]=s[i];
        else if(p==1) b[++lb]=s[i];
        else c[++lc]=s[i];
    }
    for(int i=1;i<=la;i++)
    {
        if(a[i]==b[1]&&!first)  first=find(i,2);//只需要出现的第一个位置，所以！first时才执行
         if(a[i]==c[1]) endd=max(endd,find(i,3));//需要最后一个位置，所以要取大
 
    }
    if(first==0||endd==0||first+lb>endd)   cout<<-1;//first+lb>endd，交叉的情况以及first>endd的情况都是-1
    else 
    {
        first+=lb;//first变成最大跨距中的第一个位置
        cout<<endd-first;//endd为最大跨距中的最后一个位置的后一个。例：字符串abcde中找ab、de，first开始=1，+lb=3，endd=4，ans=end-first=1
    }
}
