#include<cstdio>
#include<cstring>

bool ans, k;
int len, top1, top2;
char stk1[1001], stk2[1001], str[1002], sign;
int main(){
str[0] = '(';
while(gets(str + 1)){
len = strlen(str);
str[len] = ')';
for(int i = 0; i <= len; i ++){
if(str[i] == ')'){
while(stk1[top1] != '('){
stk2[++ top2] = stk1[top1 --];
}
k = true;
ans = true;
sign = '&';
while(top2){
if(stk2[top2] == '!'){
k ^= true;
}
else if(stk2[top2] == '&' || stk2[top2] == '|')
{
sign = stk2[top2];
}
else{
if(stk2[top2] == 'V'){
if(sign == '&'){
ans &= !(true ^ k);
}
else{
ans |= !(true ^ k);
}
k = true;
}
else{
if(sign == '&'){
ans &= !(false ^ k);
}
else{
ans |= !(false ^ k);
}
k = true;
}
}
top2 --;
}
stk1[top1] = ans == true ? 'V' : 'F';
}
else{
if(str[i] != ' '){
stk1[++ top1] = str[i];
}
}
}
printf("%c\n", stk1[top1 --]);
}
return 0;
}
