#include <cstdio>
#include <cstring>
const int N=19,M=10000;
long long f[3][55][37][20][20];
bool fl=false,fr=false;
int n,ln,rn,l2,l3,l5,l7,r2,r3,r5,r7;
int n2[10]={0,0,1,0,2,0,1,0,3,0};
int n3[10]={0,0,0,1,0,0,1,0,0,2};
int n5[10]={0,0,0,0,0,1,0,0,0,0};
int n7[10]={0,0,0,0,0,0,0,1,0,0};
struct big{
int f[20],l;
}ans,a1,b1;
void print(big a){
for(int i=a.l-1;i>=0;i--){
int j=M/10;
if(i!=a.l-1)
while(a.f[i]<j && j>1)
j/=10,printf("0");
printf("%d",a.f[i]);
}
if((a.l==1 && a.f[0]==0) || a.l<1) printf("0");
}
long long pow(int x,int y){//pow坑死人，会损失精度
long long ans=1;
for(int i=1;i<=y;i++) ans*=x;
return ans;
}
big cmp(big a,big b){
if(a.l>b.l) return a;
else if(a.l<b.l) return b;
for(int i=a.l-1;i>=0;i--)
if(a.f[i]>b.f[i]) return a;
else if(a.f[i]<b.f[i]) return b;
return a;
}
void tran(big &a,long long b){
a.l=0;
while(b) a.f[a.l++]=b%M,b/=M;
}
big add(big a,big b){
big c=cmp(a,b);int jw=0;
for(int i=0;i<c.l;i++){
c.f[i]=jw;
if(i<a.l) c.f[i]+=a.f[i];
if(i<b.l) c.f[i]+=b.f[i];
jw=c.f[i]/M,c.f[i]%=M;
}
if(jw) c.f[c.l++]=jw;
while(!c.f[c.l-1] && c.l) c.l--;
return c;
}
big minus(big a,big b){
int jw=0;
for(int i=0;i<a.l;i++){
a.f[i]-=jw;
if(i<b.l) a.f[i]-=b.f[i];
if(a.f[i]<0) jw=1,a.f[i]+=M;
}
while(!a.f[a.l-1] && a.l) a.l--;
return a;
}
big smul(big a,int b,int dig){
int jw=0;
for(int i=0;i<a.l;i++){
a.f[i]*=b,a.f[i]+=jw;
jw=a.f[i]/M,a.f[i]%=M;
}
while(jw) a.f[a.l++]=jw%M,jw/=M;
while(!a.f[a.l-1] && a.l) a.l--;
for(int i=a.l-1;i>=0;i--) a.f[i+dig]=a.f[i];
for(int i=0;i<dig;i++) a.f[i]=0;
a.l+=dig;
return a;
}
big mul(big a,big b){
big c,d;
memset(c.f,0,sizeof(c.f)),c.l=0;
for(int i=0;i<b.l;i++){
d=smul(a,b.f[i],i);
c=add(c,d);
}
while(!c.f[c.l-1] && c.l) c.l--;
return c;
}
void spj(int sp){
if(sp==-1)
if((l2==r2 &&l3==r3 && l5==r5 && l7==r7) || (fr && fl)) printf("1\n0");
else printf("0\n1");
ans.l=ans.f[0]=0;
if(sp==0){
tran(a1,pow(10,ln)),tran(b1,pow(10,rn));
ans=mul(a1,b1);
print(ans),printf("\n0");
}
if(sp==1){
tran(a1,pow(10,rn));
tran(b1,pow(9,rn));
big c1=minus(a1,b1);
tran(a1,pow(10,ln));
ans=add(ans,mul(a1,c1));
print(ans),printf("\n");
tran(a1,pow(10,ln));
tran(b1,pow(10,rn));
ans=minus(mul(a1,b1),ans);
print(ans);
}
if(sp==2){
tran(a1,pow(10,ln));
tran(b1,pow(9,ln));
big c1=minus(a1,b1);
tran(a1,pow(10,rn));
ans=add(ans,mul(a1,c1));
print(ans),printf("\n");
tran(a1,pow(10,ln));
tran(b1,pow(10,rn));
ans=minus(mul(a1,b1),ans);
print(ans);
}
}
int main(){
scanf("%d\n",&n);
for(int i=1;i<=n;i++){
char c;scanf("%c",&c);
if(c=='?') ln++;
if(c=='0') fl=true;
else l2+=n2[c-'0'],l3+=n3[c-'0'],l5+=n5[c-'0'],l7+=n7[c-'0'];
}
for(int i=1;i<=n;i++){
char c;scanf("%c",&c);
if(c=='?') rn++;
if(c=='0') fr=true;
else r2+=n2[c-'0'],r3+=n3[c-'0'],r5+=n5[c-'0'],r7+=n7[c-'0'];
}
if(!ln && !rn) {spj(-1);return 0;}
else if(fr && fl) {spj(0); return 0;}
else if(!fr && fl) {spj(1); return 0;}
else if(fr && !fl) {spj(2); return 0;}
f[0][0][0][0][0]=1;
int l1,r1,n1,m1;
if(ln>=rn) l1=ln&1,r1=2,n1=ln,m1=rn;
else l1=2,r1=rn&1,n1=rn,m1=ln;
if(!m1) f[2][0][0][0][0]=1;
for(int i=0;i<n1;i++){
memset(f[~i&1],0,sizeof(f[~i&1]));
for(int j=1;j<=9;j++)
for(int i2=0;i2<=i*3;i2++)
for(int i3=0;i3<=i*2;i3++)
for(int i5=0;i5<=i;i5++)
for(int i7=0;i7<=i;i7++)
f[~i&1][i2+n2[j]][i3+n3[j]][i5+n5[j]][i7+n7[j]]+=f[i&1][i2][i3][i5][i7];
//f[~i&1][0][0][0][0]=1;
if(i+1==m1) memcpy(f[2],f[~i&1],sizeof(f[~i&1]));
}
ans.l=ans.f[0]=0;
// for(int i2=0;i2<=n1*3;i2++)
// for(int i3=0;i3<=n1*2;i3++)
// for(int i5=0;i5<=n1;i5++)
// for(int i7=0;i7<=n1;i7++)
// printf("f[%d][%d][%d][%d][%d]: %lld\n",r1,i2,i3,i5,i7,f[r1][i2][i3][i5][i7]);
for(int i2=0;i2<=n1*3;i2++)
for(int i3=0;i3<=n1*2;i3++)
for(int i5=0;i5<=n1;i5++)
for(int i7=0;i7<=n1;i7++)
if(i2+l2>=r2 && i3+l3>=r3 && i5+l5>=r5 && i7+l7>=r7){
if(!f[l1][i2][i3][i5][i7] || !f[r1][i2+l2-r2][i3+l3-r3][i5+l5-r5][i7+l7-r7])
continue;
tran(a1,f[l1][i2][i3][i5][i7]);
tran(b1,f[r1][i2+l2-r2][i3+l3-r3][i5+l5-r5][i7+l7-r7]);
//printf("f[%d][%d][%d][%d][%d]*f[%d][%d][%d][%d][%d]\n",l1,i2,i3,i5,i7,r1,i2+l2-r2,i3+l3-r3,i5+l5-r5,i7+l7-r7);
//print(a1),printf("**"),print(b1),printf("\n");
ans=add(ans,mul(a1,b1));
}
//print(ans),printf("\n");
tran(a1,pow(10,ln));
tran(b1,pow(9,ln));
big c1=minus(a1,b1);
tran(a1,pow(10,rn));
tran(b1,pow(9,rn));
a1=minus(a1,b1);
ans=add(ans,mul(a1,c1));
print(ans),printf("\n");
tran(a1,pow(10,ln));
tran(b1,pow(10,rn));
ans=minus(mul(a1,b1),ans);
print(ans);
return 0;
}
