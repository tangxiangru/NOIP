#include "iostream"
using namespace std;
//注意这道题的样例输入的错误了，没有总次数，输入只有两行
int main(void)
{
    int n,C;
    cin>>n;
    for(int i=n;i>=0;i--){
        cin>>C;
        if (n == 0) {
            cout << 0;
        } else {
            //最后一项为常数常数的导数为0且不输出
            if(i!=0) {
                //数字之间有空格
                if(i==1)
                    cout << C*i;
                else
                    cout << C*i<<" ";
            }
        }
    }
}
