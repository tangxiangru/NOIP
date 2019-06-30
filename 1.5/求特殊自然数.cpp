#include "iostream"
using namespace std;
/*
 七进制和九进制都是三位数，说明该数十进制范围是81～342
 整数部分，（123）十进制==（234）七进制
 竖除法，逆序取余
 7 |123
 ------
 7 | 17 - 4 左边为商 右边为余数
 -----
 7| 2 - 3
 ----
 7| 0 - 2
 */
int get7(int num)//3位数
{
    int num1=0,num2=0,num3=0;
    num3=num%7;
    num=num/7;
    num2=num%7;
    num=num/7;
    num1=num;
    return num1*100+num2*10+num3;
}
int get9(int num)//3位数
{
    int num1=0,num2=0,num3=0;
    num3=num%9;
    num=num/9;
    num2=num%9;
    num=num/9;
    num1=num;
    return num1*100+num2*10+num3;
}
int getBack(int num)//3位数
{
    int num1=0,num2=0,num3=0;
    num1=num%10;
    num=num/10;
    num2=num%10;
    num=num/10;
    num3=num;
    return num1*100+num2*10+num3;
}
int main()
{
    for(int i=81;i<=342;i++)
    {
        //cout<<i<<" "<<get7(i)<<" "<<get9(i)<<" "<<getBack(get9(i))<<endl;
        if(get7(i)==getBack(get9(i)))
            cout<<i<<endl<<get7(i)<<endl<<get9(i);
    }
    return 0;
}
