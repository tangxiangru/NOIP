#include<stdio.h>
#include<string.h>
// m^n % k
long long quickpow(long long m,long long n,long long k)
{
    long long ans = 1;
    while (n > 0)
    {
          if (n & 1)
             ans = (ans*m)%k;
          n = n >> 1 ;
          m = (m*m)%k;
    }
    return ans;
}
int main(int argc, char *argv[])
{
    int k;
    int i;
    char n[205];
    int N,len;
    scanf("%d",&k);    
    for(i=0;i<k;i++)
    {
        scanf("%s",n);getchar();
        N=0;
        len=strlen(n);
        N=n[len-1]-'0';
        if(len>=2) N=(n[len-2]-'0')*10+N;
        if(len>=3) N=(n[len-3]-'0')*100+N;
        if(len>=4) N=(n[len-4]-'0')*1000+N;
        N=N%500;
        printf("%lld\n",quickpow(2011,N,10000));
    }
    return 0;
}
