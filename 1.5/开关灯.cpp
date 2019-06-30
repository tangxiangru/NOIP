#include "iostream"
using namespace std;
void process(bool flag[],int k,int M)
{
    for(int i=0;i<M;i++)
    {
        if((i+1)%k==0)
            flag[i] = !flag[i];
    }
}
int main()
{
    int M,N;
    cin>>M>>N;
    bool flag[M];
    for(int i=0;i<M;i++)
        flag[i] = true;
    for(int i=1;i<=N;i++) {
        if (i == 1) {
            for(int i=0;i<M;i++)
                flag[i] = false;
        } else {
            process(flag, i, M);
        }
    }
    bool firstF = true;
    for(int i=0;i<M;i++)
    {
        if(!flag[i])
        {
            if(firstF) {
                cout << i + 1;
                firstF = false;
            }else
                cout<<","<<i+1;
        }
    }
}
