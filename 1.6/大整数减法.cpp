#include "iostream"
using namespace std;
/**
 * 将数字从低位到高位存储到一维数组中
 * 做减法处理（注意是否需要借位）
 * 不打印首位0字符
 */
int A[202]={0};
int B[202]={0};
int result[202];
int C=0;//借位

int main() {
    //是否扫描到首个非零元素
    bool startF = false;
    string tmp;
    string strA,strB;
    cin>>strA>>strB;
//    if(strA =="0" && strB=="0")
//    {
//        cout<<"0";
//        return 0;
//    }
    //题设给定字符串长度是不一定对齐的
    int LenA = strA.length();
    int LenB = strB.length();
    for(int i=0;i<LenA;i++)
    {
        A[i] = strA[LenA-1-i]-'0';
    }
    for(int i=0;i<LenB;i++)
    {
        B[i] = strB[LenB-1-i]-'0';
    }
    int Len = LenA>LenB?LenA:LenB;
    for(int i = 0; i <= Len-1 ; i++) {
        result[i] = A[i] - B[i] + C;
        //cout<<result[i]<<endl;
        if(result[i]<0)
        {
            C = -1;
            result[i]+=10;
        }else
            C = 0;
    }
    if(C==1) {
        startF = true;
        cout<<"1";
    }
    for (int i = 0; i < Len; i++) {
        tmp += result[i]+'0';
    }
    for(int i=tmp.length()-1;i>=0;i--) {
        if (tmp[i] != '0')
            startF = true;
        if (startF)
            cout <<tmp[i];
    }
    if(C==0&&startF==false)
        cout<<"0";
    return 0;
}
