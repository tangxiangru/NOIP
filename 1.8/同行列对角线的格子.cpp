
#include "iostream"
using namespace std;
int main()
{
    int N,i,j;
    cin>>N>>i>>j;
    //行
    for(int k=1;k<=N;k++)
    {
        cout<<"("<<i<<","<<k<<")"<<" ";
    }
    cout<<endl;
    //列
    for(int k=1;k<=N;k++)
    {
        cout<<"("<<k<<","<<j<<")"<<" ";
    }
    cout<<endl;
    //左上到右下
    for(int k =-(N-1);k<=(N-1);k++)
    {
        if(i+k>=1&&i+k<=N&&j+k>=1&&j+k<=N) {
            cout << "(" << i + k << "," << j+k << ")"<<" ";
        }
    }
    cout<<endl;
    //左下到右上
    for(int k =-(N-1);k<=(N-1);k++)
    {
        if(i-k>=1&&i-k<=N&&j+k>=1&&j+k<=N) {
            cout << "(" << i - k << "," << j+k << ")"<<" ";
        }
    }
    return 0;

