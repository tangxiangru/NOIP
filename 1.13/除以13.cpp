#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main(){
    int num[101]={0},yun,ans[101],count=0,yu;
    char a[101];
    gets(a);
    for(int i=0;i<strlen(a);i++)
        num[i]=a[i]-'0';
        yun=num[0]*10+num[1];
        if(strlen(a)==1)
        yun=num[0];
        if(strlen(a)<=2&&yun<=13){
            cout<<yun/13<<endl<<yun%13;
            return 0;
        }
    for(int i=0;i<strlen(a)-1;i++){
 
        if(yun<13){
            if(i!=0)
            ans[count++]=0;
            yu=yun;
            yun=yun*10+num[i+2];
        } 
        else{
            ans[count++]=yun/13;
            yun%=13;
            yu=yun;
            yun=yun*10+num[i+2];
            //cout<<"yun is:"<<yun<<endl;
        }
    }
    for(int i=0;i<count;i++)
    cout<<ans[i];
    cout<<endl<<yu;
    return 0;
} 


