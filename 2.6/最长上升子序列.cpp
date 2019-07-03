#include<cstdio>  
#include<algorithm>  
using namespace std;  
int n,a[6006],ans=-1,t,f[6006],c[6006];  
void out(int syx){  
    if(c[syx]){  
        out(c[syx]);  
        printf(" ");  
    }  
    printf("%d",a[syx]);  
}  
int main()  
{  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++)   
        scanf("%d",&a[i]);  
    for(int i=1;i<=n;i++){
        int e=0;
        for(int j=1;j<i;j++)  
            if(a[j]<a[i]&&e<f[j])  
                e=f[j],c[i]=j;  
        f[i]=e+1;  
        if(ans<f[i])
            ans=f[i],t=i;  
    }
    printf("%d\n",ans);  
    out(t);
}
